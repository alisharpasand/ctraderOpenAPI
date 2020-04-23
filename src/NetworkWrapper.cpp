#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netdb.h>
#include <OpenApiMessagesFactory.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <zconf.h>
#include "NetworkWrapper.h"

#define CHK_NULL(x) if ((x)==NULL) exit (1)
#define CHK_ERR(err,s) if ((err)==-1) { perror(s); exit(1); }
#define CHK_SSL(err) if ((err)==-1) { ERR_print_errors_fp(stderr); exit(2); }
using namespace std;

NetworkWrapper::NetworkWrapper() :
        readThread_(&NetworkWrapper::readTask, this),
        writeThread_(&NetworkWrapper::writeTask, this),
        callbackThread_(&NetworkWrapper::callbackTask, this)
{

}

int NetworkWrapper::writeSSLSocket(SSL *sslx, char *msg, uint16_t size)
{
    int err = 0;
    /* --------------------------------------------------- */
    /* DATA EXCHANGE - Send a message and receive a reply. */
    err = SSL_write (sslx, msg, size);
    CHK_SSL(err);
    return err;
}

google::protobuf::uint32 readHdr(char *buf)
{
    int size;
    memcpy(&size, buf, 4);
    size = ntohl(size);
    return size;
}

unsigned NetworkWrapper::readSSLSocket(SSL *sslx, char *& buf)
{
    char *headbuf = (char *)malloc(4);
    int ret = SSL_read (sslx, headbuf, 4);
    if (ret != 4)
    {
        delete headbuf;
        return 0;
    }

    unsigned size = readHdr(headbuf);
    delete headbuf;

    buf = (char *)malloc(size);
    unsigned remainingSize = size;
    char *cursor = buf;
    while (remainingSize > 0)
    {
        int ret = SSL_read(sslx, cursor, remainingSize);

        if (ret < 0)
            return 0;

        if (ret == 0)
            continue;

        remainingSize -= ret;
        cursor += ret;
    }

    return size;
}

void NetworkWrapper::join()
{
    callbackThread_.join();
    readThread_.join();
    writeThread_.join();
}

int NetworkWrapper::openSSLSocket()
{
    int err = 0;
    struct hostent *host_entry;
    struct sockaddr_in sa;
    const SSL_METHOD *meth = TLSv1_2_client_method();

    OpenSSL_add_ssl_algorithms();
    SSL_load_error_strings();
    ctx_ = SSL_CTX_new(meth);
    CHK_NULL(ctx_);

    /* ----------------------------------------------- */
    /* Create a socket and connect to server using normal socket calls. */

    sd_ = socket(AF_INET, SOCK_STREAM, 0);
    CHK_ERR(sd_, "socket");

    memset(&sa, 0, sizeof(sa));
    host_entry = gethostbyname(apiHost_.c_str());
    sa.sin_family      = AF_INET;
    sa.sin_addr        = *((struct in_addr *)host_entry->h_addr);
    sa.sin_port        = htons(apiPort_);

    err = connect(sd_, (struct sockaddr*) &sa,
                  sizeof(sa));
    CHK_ERR(err, "connect");

    /* ----------------------------------------------- */
    /* Now we have TCP conncetion. Start SSL negotiation. */
    ssl_ = SSL_new(ctx_);
    CHK_NULL(ssl_);
    SSL_set_fd(ssl_, sd_);
    err = SSL_connect(ssl_);
    CHK_SSL(err);

    /* Get the cipher - opt */
    printf("SSL connection using %s\n", SSL_get_cipher (ssl_));

    /* Get server's certificate (note: beware of dynamic allocation) - opt */
    //printfCertInfo(ssl);

    return err;
}

void NetworkWrapper::transmit(const ProtoMessage& message)
{
    size_t size = message.ByteSize();
    char *pkt = new char [size+4];
    int nsize = htonl(size);
    memcpy(pkt, &nsize, 4);
    message.SerializeToArray(pkt+4, size);

    NetworkMessage networkMessage;
    networkMessage.data = std::shared_ptr<char>(pkt);
    networkMessage.size = size + 4;
    writeBuffer_.add(networkMessage);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void NetworkWrapper::callbackTask()
{
    while (true)
    {
        ProtoMessage protoMessage;
        { // To release net message memory before doing the callback.
            NetworkMessage message = readBuffer_.remove();
            OpenApiMessagesFactory msgFactory;
            protoMessage = msgFactory.GetMessage(message.data.get(), message.size);
        }
        if(messageHandler)
            messageHandler->handleMessage(protoMessage);
    }
}
#pragma clang diagnostic pop

void NetworkWrapper::startConnection(std::string server, int port) {
    apiHost_ = server;
    apiPort_ = port;
    openSSLSocket();

    listening_ = true;
}

void NetworkWrapper::writeTask()
{
    while (!listening_)
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

    while (listening_)
    {
        NetworkMessage message = writeBuffer_.remove();
        writeSSLSocket(ssl_, message.data.get(), message.size);
    }

}

void NetworkWrapper::readTask()
{
    while (!listening_)
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

    while (listening_)
    {
        char *buf;
        unsigned size = readSSLSocket(ssl_, buf);
        if (size == 0)
            continue;

        NetworkMessage message;
        message.data = std::shared_ptr<char>(buf);
        message.size = size;
        readBuffer_.add(message);
    }
}

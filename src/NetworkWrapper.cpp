#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netdb.h>
#include <OpenApiMessagesFactory.h>
#include "NetworkWrapper.h"

#define CHK_NULL(x) if ((x)==NULL) exit (1)
#define CHK_ERR(err,s) if ((err)==-1) { perror(s); exit(1); }
#define CHK_SSL(err) if ((err)==-1) { ERR_print_errors_fp(stderr); exit(2); }
using namespace std;

NetworkWrapper::NetworkWrapper()
{

}

NetworkWrapper& NetworkWrapper::getInstance()
{
    static NetworkWrapper instance;
    return instance;
}


void NetworkWrapper::printfCertInfo(SSL *sslx)
{
    char*    str;
    X509*    server_cert;
    //EVP_PKEY *pubkey;
    //int pkeyLen;
    //unsigned char *ucBuf, *uctempBuf;

    server_cert = SSL_get_peer_certificate (sslx);
    CHK_NULL(server_cert);
    printf ("Server certificate:\n");

    str = X509_NAME_oneline (X509_get_subject_name (server_cert),0,0);
    CHK_NULL(str);
    printf ("\t subject: %s\n", str);
    OPENSSL_free (str);

    //str = X509_NAME_oneline (X509_get_issuer_name  (server_cert),0,0);
    //CHK_NULL(str);
    //printf ("\t issuer: %s\n", str);
    //OPENSSL_free (str);

    /* We could do all sorts of certificate verification stuff here before
        deallocating the certificate. */

    X509_free (server_cert);
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

int NetworkWrapper::readSSLSocket(SSL *sslx)
{
    memset(_buf, 0, sizeof(_buf));
    int err = SSL_read (sslx, _buf, sizeof(_buf) - 1);
    CHK_SSL(err);
    //buf[err] = '\0';
    return err;
}

void NetworkWrapper::join()
{
    pthread_join(_readThread, NULL);
}

int NetworkWrapper::openSSLSocket()
{
    int err = 0;
    struct hostent *host_entry;
    struct sockaddr_in sa;
    const SSL_METHOD *meth = TLSv1_2_client_method();

    OpenSSL_add_ssl_algorithms();
    SSL_load_error_strings();
    _ctx = SSL_CTX_new (meth);
    CHK_NULL(_ctx);

    /* ----------------------------------------------- */
    /* Create a socket and connect to server using normal socket calls. */

    _sd = socket (AF_INET, SOCK_STREAM, 0);
    CHK_ERR(_sd, "socket");

    memset(&sa, 0, sizeof(sa));
    host_entry = gethostbyname(_apiHost.c_str());
    sa.sin_family      = AF_INET;
    sa.sin_addr        = *((struct in_addr *)host_entry->h_addr);
    sa.sin_port        = htons(_apiPort);

    err = connect(_sd, (struct sockaddr*) &sa,
                  sizeof(sa));
    CHK_ERR(err, "connect");

    /* ----------------------------------------------- */
    /* Now we have TCP conncetion. Start SSL negotiation. */
    _ssl = SSL_new (_ctx);
    CHK_NULL(_ssl);
    SSL_set_fd (_ssl, _sd);
    err = SSL_connect (_ssl);
    CHK_SSL(err);

    /* Get the cipher - opt */
    printf ("SSL connection using %s\n", SSL_get_cipher (_ssl));

    /* Get server's certificate (note: beware of dynamic allocation) - opt */
    //printfCertInfo(ssl);

    return err;
}

void NetworkWrapper::transmit(const ProtoMessage& message)
{
    std::string msgStr;
    unsigned char sizeArray[4];
    size_t size = message.ByteSize();
    auto *pkt = new unsigned char [size];

    message.SerializeToArray(pkt, size);
    // little endian to big endian
    size = htonl(size);
    memcpy(sizeArray, &size, 4);
    //
    writeSSLSocket(_ssl, (char*)sizeArray, 4);
    writeSSLSocket(_ssl, (char*)pkt, message.ByteSize());
}

void *NetworkWrapper::read_task(void *arg)
{
    int ret = 0;
    int length, num;
    OpenApiMessagesFactory msgFactory;
    ProtoMessage protoMessage;

    while (NetworkWrapper::getInstance()._listening)
    {
        length = 0;
        ret = NetworkWrapper::getInstance().readSSLSocket(NetworkWrapper::getInstance()._ssl);
        auto& buf = NetworkWrapper::getInstance()._buf;
        if (ret > 0)
        {
            memcpy(&num, buf, 4);
            // big endian to little endian
            length = ntohl(num);
            //printf("length: %d\n", length);
        }
        if (length > 0)
        {
            string _message(buf+4);
            std::cout << _message << std::endl;
            protoMessage = msgFactory.GetMessage(_message);
            auto& handler = NetworkWrapper::getInstance().messageHandler;
            if(handler)
                handler->handleMessage(protoMessage);
        }
        //usleep(100000);
    }
    pthread_exit(&ret);
}

void NetworkWrapper::startConnection(std::string server, int port) {
    _apiHost = server;
    _apiPort = port;
    openSSLSocket();

    _listening = true;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
//    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&_readThread, &attr, read_task, nullptr);
}

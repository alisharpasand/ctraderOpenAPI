#ifndef CTRADEROPENAPI_NETWORKWRAPPER_H
#define CTRADEROPENAPI_NETWORKWRAPPER_H


#include <openssl/ossl_typ.h>
#include <cstdint>
#include <OpenApiCommonMessages.pb.h>
#include <iostream>
#include "MessageHandler.h"

class NetworkWrapper {
public:
    static NetworkWrapper& getInstance();
    NetworkWrapper(NetworkWrapper const&) = delete;
    void operator=(NetworkWrapper const&) = delete;

    void startConnection(std::string server, int port);
    void printfCertInfo(SSL *sslx);
    int writeSSLSocket(SSL *sslx, char *msg, uint16_t size);
    static unsigned readSSLSocket(SSL *sslx, char *& buf);
    void join();
    int openSSLSocket();
    void transmit(const ProtoMessage& message);
    MessageHandler *messageHandler = nullptr;


private:
    int _sd;
    SSL_CTX* _ctx;
    SSL* _ssl;
    std::string _apiHost = "demo.ctraderapi.com";
    int _apiPort = 5035;
    bool _listening = false;
    pthread_t _readThread;

    static void *read_task(void *arg);
    NetworkWrapper();
};

#endif //CTRADEROPENAPI_NETWORKWRAPPER_H

#ifndef CTRADEROPENAPI_NETWORKWRAPPER_H
#define CTRADEROPENAPI_NETWORKWRAPPER_H


#include <openssl/ossl_typ.h>
#include <cstdint>
#include <OpenApiCommonMessages.pb.h>
#include <iostream>
#include <Buffer.h>
#include <NetworkMessage.h>
#include <thread>
#include "MessageHandler.h"

class NetworkWrapper {
public:
    NetworkWrapper();
    NetworkWrapper(NetworkWrapper const&) = delete;
    NetworkWrapper operator=(NetworkWrapper const&) = delete;

    void startConnection(std::string server, int port);
    void transmit(const ProtoMessage& message);
    void join();

    MessageHandler *messageHandler = nullptr;

private:
    int sd_;
    SSL_CTX* ctx_;
    SSL* ssl_;
    std::string apiHost_ = "demo.ctraderapi.com";
    int apiPort_ = 5035;
    bool listening_ = false;

    Buffer<NetworkMessage, 50> readBuffer_;
    Buffer<NetworkMessage, 50> writeBuffer_;
    std::thread readThread_;
    std::thread writeThread_;
    std::thread callbackThread_;

    void readTask();
    void writeTask();

    void callbackTask();
    int writeSSLSocket(SSL *sslx, char *msg, uint16_t size);
    static unsigned readSSLSocket(SSL *sslx, char *& buf);
    int openSSLSocket();
};

#endif //CTRADEROPENAPI_NETWORKWRAPPER_H

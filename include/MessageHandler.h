#ifndef CTRADEROPENAPI_MESSAGEHANDLER_H
#define CTRADEROPENAPI_MESSAGEHANDLER_H

#include "OpenApiCommonMessages.pb.h"

class MessageHandler {
public:
    virtual void handleMessage(ProtoMessage message) = 0;
};


#endif //CTRADEROPENAPI_MESSAGEHANDLER_H

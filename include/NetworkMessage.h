#ifndef CTRADEROPENAPI_NETWORKMESSAGE_H
#define CTRADEROPENAPI_NETWORKMESSAGE_H

#include <memory>

class NetworkMessage
{
public:
    std::shared_ptr<char> data;
    unsigned size;
};

#endif //CTRADEROPENAPI_NETWORKMESSAGE_H

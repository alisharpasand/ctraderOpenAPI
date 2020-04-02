#ifndef CTRADEROPENAPI_OPENAPI_H
#define CTRADEROPENAPI_OPENAPI_H

#include <list>
#include "OpenApiMessagesFactory.h"
#include "NetworkWrapper.h"
#include "MessageHandler.h"

class OpenApi : public MessageHandler{
public:
    OpenApi();

    void connect(std::string server, int port, std::string clientId, std::string clientSecret, std::string token, long accountId);

    void authorizeApplication();
    void authorizeAccount();
    void getAccountsList();
    void subscribeForSpots();
    void unSubscribeFromSpots();
    void SendMarketOrder(int symbol, ProtoOATradeSide side, long volume);
    void GetOrders();
    void GetTickData(int days, int symbol);
    void SendStopOrder(int symbol, ProtoOATradeSide side, int volume, double stopPrice);
    void ClosePosition(long positionId, long volume);
    void SendLimitOrder(ProtoOATradeSide side, int volume, double price);
    void heartBeatACK();
    void GetSymbols();

    std::function<void(void)> onAppAuthorized;
    std::function<void(void)> onAccAuthorized;
    std::function<void(ProtoOAGetAccountListByAccessTokenRes)> onAccountListReceived;
    std::function<void(void)> onSpotsSubscribed;
    std::function<void(void)> onSpotsUnsubscribed;
    std::function<void(ProtoOASpotEvent)> onSpotReceived;
    std::function<void(ProtoOAExecutionEvent)> onOrderExecuted;
    std::function<void(ProtoOAReconcileRes)> onOrdersReceived;
    std::function<void(ProtoOAGetTickDataRes)> onTickDataReceived;
    std::function<void(ProtoOATraderRes)> onTraderReceived;
    std::function<void(ProtoOAOrderErrorEvent)> onOrderErrorReceived;
    std::function<void(ProtoOAErrorRes)> onErrorReceived;
    std::function<void(ProtoOASymbolsListRes)> onSymbolListReceived;

private:
    std::string _clientId;
    std::string _clientSecret;
    std::string _token;
    long _accountID;
    NetworkWrapper& _net;

    void handleMessage(ProtoMessage message);
    OpenApiMessagesFactory messageFactory;
};


#endif //CTRADEROPENAPI_OPENAPI_H

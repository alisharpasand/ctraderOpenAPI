#include "OpenApi.h"

#include <iostream>
using namespace std;

OpenApi::OpenApi() :
    _net(NetworkWrapper::getInstance())
{
    _net.messageHandler = this;
}

void OpenApi::connect(std::string server, int port, std::string clientId, std::string clientSecret, std::string token,
                      long accountId)
{
    _clientId = clientId;
    _clientSecret = clientSecret;
    _token = token;
    _accountID = accountId;

    _net.startConnection(server, port);
}

void OpenApi::join()
{
    _net.join();
}

void OpenApi::authorizeApplication()
{
    ProtoMessage msg = messageFactory.CreateAppAuthorizationRequest(_clientId,
                                                                    _clientSecret);
    _net.transmit(msg);
}

void OpenApi::authorizeAccount()
{
    ProtoMessage msg = messageFactory.CreateAccAuthorizationRequest(_token,
                                                                    _accountID);
    _net.transmit(msg);
//    // Wait for response
//    pthread_mutex_lock(&mutex_resp);
//    pthread_cond_wait(&wait_resp, &mutex_resp);
//    pthread_mutex_unlock(&mutex_resp);
//    msg = messageFactory.CreateTraderRequest(_accountID);
//    _net.transmit(msg);
}

void OpenApi::getAccountsList()
{
    //int i = 0;
    //std::list<ProtoOACtidTraderAccount>::iterator it;
    //ProtoOACtidTraderAccount _acc_list;
    ProtoMessage msg = messageFactory.CreateAccountListRequest(_token);
    _net.transmit(msg);
//    // Wait for response
//    pthread_mutex_lock(&mutex_resp);
//    pthread_cond_wait(&wait_resp, &mutex_resp);
//    pthread_mutex_unlock(&mutex_resp);
//    /*for (it = _accounts.begin(); it < _accounts.end(); it++) {
//        //_acc_list = it;
//        msg = messageFactory.CreateAccAuthorizationRequest(_token,
//            _acc_list.ctidtraderaccountid());
//        transmit(msg);
//        // Wait for response
//        pthread_mutex_lock(&mutex_resp);
//        pthread_cond_wait(&wait_resp, &mutex_resp);
//        pthread_mutex_unlock(&mutex_resp);
//        msg = messageFactory.CreateTraderRequest(_acc_list.ctidtraderaccountid());
//        transmit(msg);
//    }*/
}

void OpenApi::subscribeForSpots(int symbolId)
{
    ProtoMessage msg = messageFactory.CreateSubscribeForSpotsRequest(_accountID, symbolId);
    _net.transmit(msg);
}

void OpenApi::unSubscribeFromSpots(int symbolId)
{
    ProtoMessage msg = messageFactory.CreateUnsubscribeFromSpotsRequest(_accountID, 1);
    _net.transmit(msg);
}

void OpenApi::SendLimitOrder(int symbol,
                             ProtoOATradeSide side,
                             long volume,
                             double limitPrice,
                             double stopLoss,
                             double takeProfit,
                             long expirationTimestamp,
                             std::string clientMsgId)
{
    ProtoMessage msg = messageFactory.CreateLimitOrderRequest(_accountID,
                                                              _token,
                                                              symbol,
                                                              side,
                                                              volume,
                                                              limitPrice,
                                                              stopLoss,
                                                              takeProfit,
                                                              expirationTimestamp,
                                                              clientMsgId);
    _net.transmit(msg);
}

void OpenApi::GetOrders()
{
    ProtoMessage msg = messageFactory.CreateReconcileRequest(_accountID);
    _net.transmit(msg);
}

void OpenApi::GetTickData(int days, int symbol)
{
    long time_end = days * 24 * 60 * 60;
    ProtoMessage msg = messageFactory.CreateTickDataRequest(_accountID, symbol,
                                                        (time(NULL) - time_end)*1000, time(NULL)*1000, BID);
    _net.transmit(msg);
}

void OpenApi::SendStopOrder(int symbol, ProtoOATradeSide side, int volume, double stopPrice)
{
    ProtoMessage msg = messageFactory.CreateStopOrderRequest(_accountID,
                                                             _token, symbol, side, volume, stopPrice);
    _net.transmit(msg);
}

void OpenApi::ClosePosition(long positionId, long volume)
{
    ProtoMessage msg = messageFactory.CreateClosePositionRequest(_accountID,
                                                                 positionId, volume);
    _net.transmit(msg);
}

void OpenApi::heartBeatACK()
{
    ProtoMessage msg = messageFactory.CreateHeartbeatEvent();
    _net.transmit(msg);
}

void OpenApi::GetSymbols() {
    ProtoMessage msg = messageFactory.CreateProtoOASymbolsListReq(_accountID);
    _net.transmit(msg);
}

void OpenApi::handleMessage(ProtoMessage message)
{
    int msgType = message.payloadtype();
    if (msgType != HEARTBEAT_EVENT)
        cout << "MsgType: " << msgType << endl;

    switch (msgType)
    {
        case HEARTBEAT_EVENT:
            //cout << "Heart Beat" << endl;
            heartBeatACK();
            break;

        case PROTO_OA_APPLICATION_AUTH_RES:
            cout << "App Auth res\n";
            if(onAppAuthorized)
                onAppAuthorized();
            break;

        case PROTO_OA_ACCOUNT_AUTH_RES:
        {
            cout << "Account Auth res\n";
            ProtoOAAccountAuthRes msg;
            msg.ParseFromString(message.payload());
            if (msg.has_ctidtraderaccountid())
                cout << "CtidAccID " <<
                     msg.ctidtraderaccountid() << endl;
            if(onAccAuthorized)
                onAccAuthorized();
        }
            break;

        case PROTO_OA_TRADER_RES:
        {
            cout << "TraderResp\n";
            ProtoOATraderRes msg;
            msg.ParseFromString(message.payload());
            if (msg.trader().has_balance())
                cout << "Balance " << msg.trader().balance() <<
                     endl;
            if (msg.trader().has_leverageincents())
                cout << "Leverage " <<
                     msg.trader().leverageincents() << endl;
            if (msg.trader().has_brokername())
                cout << "Broker " <<
                     msg.trader().brokername() << endl;
            if(onTraderReceived)
                onTraderReceived(msg);
        }
            break;

        case PROTO_OA_EXECUTION_EVENT:
        {
            cout << "Event\n";
            ProtoOAExecutionEvent _payload_msg =
                    messageFactory.GetExecutionEvent(message.payload());
            if(onOrderExecuted)
                onOrderExecuted(_payload_msg, message.has_clientmsgid() ? message.clientmsgid() : "");
        }
            break;

        case PROTO_OA_SUBSCRIBE_SPOTS_RES:
            cout << "SpotSubRes" << endl;
            if(onSpotsSubscribed)
                onSpotsSubscribed();
            break;

        case PROTO_OA_UNSUBSCRIBE_SPOTS_RES:
            cout << "SpotUnsubRes" << endl;
            if(onSpotsUnsubscribed)
                onSpotsUnsubscribed();
            break;

        case PROTO_OA_SPOT_EVENT:
        {
            cout << "SpotEvet: " << endl;
            ProtoOASpotEvent spotEvent;
            spotEvent.ParseFromString(message.payload());
            if (spotEvent.has_bid())
                cout << "Bid " << spotEvent.bid() << endl;
            if (spotEvent.has_ask())
                cout << "Ask " << spotEvent.ask() << endl;
            if(onSpotReceived)
                onSpotReceived(spotEvent);
        }
            break;

        case PROTO_OA_RECONCILE_RES:
        {
            cout << "Orders Received." << endl;
            ProtoOAReconcileRes reconcileRes;
            reconcileRes.ParseFromString(message.payload());
            if(onOrdersReceived)
                onOrdersReceived(reconcileRes);
        }
            break;

        case PROTO_OA_GET_TICKDATA_RES:
        {
            cout << "Tick Data Received." << endl;
            ProtoOAGetTickDataRes tickData;
            tickData.ParseFromString(message.payload());
            if(onTickDataReceived)
                onTickDataReceived(tickData);
        }
            break;

        case PROTO_OA_ORDER_ERROR_EVENT:
        {
            cout << "OrderError: " << endl;
            ProtoOAOrderErrorEvent orderErr;
            orderErr.ParseFromString(message.payload());
            if (orderErr.has_description())
                cout << "Err: " << orderErr.description() << endl;
            if(onOrderErrorReceived)
                onOrderErrorReceived(orderErr);
        }
            break;

        case PROTO_OA_ERROR_RES:
        {
            ProtoOAErrorRes errorRes;
            errorRes.ParseFromString(message.payload());
            cout << "Error\n";
            cout << "Payload: " << errorRes.description() << endl;
            if (onErrorReceived)
                onErrorReceived(errorRes);
        }
            break;

        case PROTO_OA_GET_ACCOUNTS_BY_ACCESS_TOKEN_RES:
        {
            cout << "Accounts Access TokenRes\n";
            ProtoOAGetAccountListByAccessTokenRes _acc_list;
            _acc_list.ParseFromString(message.payload());
            if(onAccountListReceived)
                onAccountListReceived(_acc_list);
        }
            break;

        case PROTO_OA_SYMBOLS_LIST_RES:
        {
            cout << "Symbol List\n";
            ProtoOASymbolsListRes res;
            res.ParseFromString(message.payload());
            if(onSymbolListReceived)
                onSymbolListReceived(res);
        }
            break;

        default:
            break;
    }
}

void OpenApi::SendAmendPositionSLTPReq(long positionId, double stopLossPrice, double takeProfitPrice)
{
    ProtoMessage msg = messageFactory.CreateAmendPositionSLTPRequest(_accountID, positionId, stopLossPrice, takeProfitPrice);
}


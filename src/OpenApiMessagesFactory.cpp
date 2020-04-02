
#include "OpenApiMessages.pb.h"
#include "OpenApiModelMessages.pb.h"
#include "OpenApiCommonMessages.pb.h"
#include "OpenApiCommonModelMessages.pb.h"
#include "OpenApiMessagesFactory.h"

using namespace std;

string OpenApiMessagesFactory::getLastMessage(void)
{
    return lastMessagePayload;
}

ProtoMessage OpenApiMessagesFactory::GetMessage(string msg)
{
    ProtoMessage _msg;
    _msg.ParseFromString(msg);
    lastMessagePayloadType = _msg.payloadtype();
    lastMessagePayload = _msg.payload();
    return _msg;
}

ProtoMessage OpenApiMessagesFactory::CreateMessage(uint payloadType,
    string &payload, string &clientMsgId)
{
    ProtoMessage protoMsg;

    protoMsg.set_payloadtype(payloadType);
    protoMsg.set_payload(payload);
    protoMsg.set_clientmsgid(clientMsgId);

    return protoMsg;
}

ProtoMessage OpenApiMessagesFactory::CreateMessage(uint payloadType,
                string &payload)
{
    ProtoMessage protoMsg;

    protoMsg.set_payloadtype(payloadType);
    protoMsg.set_payload(payload);

    return protoMsg;
}

ProtoMessage OpenApiMessagesFactory::CreateAppAuthorizationRequest(string clientId,
    string clientSecret)
{
    ProtoOAApplicationAuthReq _msg;
    string msg_str;
    _msg.set_clientid(clientId);
    _msg.set_clientsecret(clientSecret);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateAccAuthorizationRequest(string token,
    long accountId)
{
    ProtoOAAccountAuthReq _msg;
    string msg_str;
    _msg.set_accesstoken(token);
    _msg.set_ctidtraderaccountid(accountId);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateAccountListRequest(string token)
{
    ProtoOAGetAccountListByAccessTokenReq _msg;
    string msg_str;
    _msg.set_accesstoken(token);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateTraderRequest(long accountID)
{
    ProtoOATraderReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountID);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateSubscribeForSpotsRequest(
        long accountId, int symbolId)
{
    ProtoOASubscribeSpotsReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.add_symbolid(symbolId);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateUnsubscribeFromSpotsRequest(
    long accountId,int symbolId)
{
    ProtoOAUnsubscribeSpotsReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.add_symbolid(symbolId);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateHeartbeatEvent(void)
{
    ProtoHeartbeatEvent _msg;
    string msg_str;
    _msg.SerializeToString(&msg_str);

    return CreateMessage(HEARTBEAT_EVENT, msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateMarketOrderRequest(long accountId,
    string accessToken, int symbolId, ProtoOATradeSide tradeSide, long volume)
{
    ProtoOANewOrderReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_symbolid(symbolId);
    _msg.set_ordertype(MARKET);
    _msg.set_tradeside(tradeSide);
    _msg.set_volume(volume);
    _msg.set_comment("MarketOrder");
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateStopOrderRequest(long accountId,
    string accessToken, int symbolId, ProtoOATradeSide tradeSide, long volume,
    double stopPrice)
{
    ProtoOANewOrderReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_symbolid(symbolId);
    _msg.set_ordertype(STOP);
    _msg.set_tradeside(tradeSide);
    _msg.set_volume(volume);
    _msg.set_stopprice(stopPrice);
    _msg.set_comment("StopOrder");
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateLimitOrderRequest(long accountId,
    string accessToken, int symbolId, ProtoOATradeSide tradeSide, long volume,
    double limitPrice)
{
    ProtoOANewOrderReq _msg;
    string msg_str;
    long epoch = (time(NULL) + 60) * 1000;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_symbolid(symbolId);
    _msg.set_ordertype(LIMIT);
    _msg.set_tradeside(tradeSide);
    _msg.set_volume(volume);
    _msg.set_limitprice(limitPrice);
    _msg.set_comment("LimitOrder");
    _msg.set_expirationtimestamp(epoch);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateStopLimitOrderRequest(long accountId,
    string accessToken, int symbolId, ProtoOATradeSide tradeSide, long volume,
    double stopPrice, int slippageInPoints)
{
    ProtoOANewOrderReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_symbolid(symbolId);
    _msg.set_ordertype(STOP_LIMIT);
    _msg.set_tradeside(tradeSide);
    _msg.set_volume(volume);
    _msg.set_slippageinpoints(slippageInPoints);
    _msg.set_stopprice(stopPrice);
    _msg.set_comment("StopLimitOrder");
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateCancelOrderRequest(long accountId,
    long orderId)
{
    ProtoOACancelOrderReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_orderid(orderId);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateClosePositionRequest(long accountId,
    long positionId, long volume)
{
    ProtoOAClosePositionReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_positionid(positionId);
    _msg.set_volume(volume);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateAmendPositionStopLossRequest(
    long accountId, long positionId, double stopLossPrice)
{
    ProtoOAAmendPositionSLTPReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_positionid(positionId);
    _msg.set_stoploss(stopLossPrice);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateAmendPositionTakeProfitRequest(
    long accountId, long positionId, double takeProfitPrice)
{
    ProtoOAAmendPositionSLTPReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_positionid(positionId);
    _msg.set_takeprofit(takeProfitPrice);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateAmendPositionSLTPRequest(
    long accountId, long positionId, double stopLossPrice,
    double takeProfitPrice)
{
    ProtoOAAmendPositionSLTPReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_positionid(positionId);
    _msg.set_stoploss(stopLossPrice);
    _msg.set_takeprofit(takeProfitPrice);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateAmendLimitOrderRequest(
    long accountId, long orderId, double limitPrice)
{
    ProtoOAAmendOrderReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_orderid(orderId);
    _msg.set_limitprice(limitPrice);
    _msg.set_takeprofit(limitPrice + 0.02);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}
ProtoMessage OpenApiMessagesFactory::CreateAmendStopOrderRequest(long accountId,
    long orderId, double stopPrice)
{
    ProtoOAAmendOrderReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_orderid(orderId);
    _msg.set_stopprice(stopPrice);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateReconcileRequest(long accountId)
{
    ProtoOAReconcileReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoMessage OpenApiMessagesFactory::CreateTickDataRequest(long accountId,
    int symbolId, long from, long to, ProtoOAQuoteType type)
{
    ProtoOAGetTickDataReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(accountId);
    _msg.set_symbolid(symbolId);
    _msg.set_type(type);
    _msg.set_fromtimestamp(from);
    _msg.set_totimestamp(to);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoOAExecutionEvent OpenApiMessagesFactory::GetExecutionEvent(string msg)
{
    ProtoOAExecutionEvent _msg;
    _msg.ParseFromString(msg);
    return _msg;
}

ProtoMessage OpenApiMessagesFactory::CreateProtoOASymbolsListReq(long ctid) {
    ProtoOASymbolsListReq _msg;
    string msg_str;
    _msg.set_ctidtraderaccountid(ctid);
    _msg.SerializeToString(&msg_str);

    return CreateMessage(_msg.payloadtype(), msg_str);
}

ProtoOASymbolsListRes OpenApiMessagesFactory::GetSymbolListRes(string msg) {
    ProtoOASymbolsListRes res;
    res.ParseFromString(msg);
    return res;
}

#ifndef CTRADEROPENAPI_OPENAPIMESSAGEFACTORY_H
#define CTRADEROPENAPI_OPENAPIMESSAGEFACTORY_H

#include <string>
#include "OpenApiMessages.pb.h"
#include "OpenApiModelMessages.pb.h"
#include "OpenApiCommonMessages.pb.h"
#include "OpenApiCommonModelMessages.pb.h"

using namespace std;

class OpenApiMessagesFactory
{
    uint lastMessagePayloadType;
    string lastMessagePayload;

public:

    string getLastMessage(void);
    ProtoMessage GetMessage(string msg);
    ProtoMessage CreateMessage(uint payloadType, string &payload,
                string &clientMsgId);
    ProtoMessage CreateMessage(uint payloadType, string &payload);

    ProtoMessage CreateAppAuthorizationRequest(string clientId,
        string clientSecret);
    ProtoMessage CreateAccAuthorizationRequest(string token,
        long accountId);
    ProtoMessage CreateAccountListRequest(string token);
    ProtoMessage CreateSubscribeForSpotsRequest(long accountId, int symbolId);
    ProtoMessage CreateUnsubscribeFromSpotsRequest(long accountId,int symbolId);
    ProtoMessage CreateTraderRequest(long accountID);
    ProtoMessage CreateHeartbeatEvent(void);
    ProtoMessage CreateReconcileRequest(long accountId);

    ProtoMessage CreateLimitOrderRequest(long accountId,
                                         string accessToken,
                                         int symbolId,
                                         ProtoOATradeSide tradeSide,
                                         long volume,
                                         double limitPrice,
                                         double stopLoss,
                                         double takeProfit,
                                         long expirationTimestamp);

    ProtoMessage CreateStopOrderRequest(long accountId, string accessToken,
        int symbolId, ProtoOATradeSide tradeSide, long volume,
        double stopPrice);

    ProtoMessage CreateLimitOrderRequest(long accountId,
        string accessToken, int symbolId, ProtoOATradeSide tradeSide,
        long volume, double limitPrice);

    ProtoMessage CreateStopLimitOrderRequest(long accountId, string accessToken,
        int symbolId, ProtoOATradeSide tradeSide, long volume, double stopPrice,
        int slippageInPoints);

    ProtoMessage CreateCancelOrderRequest(long accountId, long orderId);

    ProtoMessage CreateClosePositionRequest(long accountId, long positionId,
        long volume);

    ProtoMessage CreateAmendPositionStopLossRequest(long accountId,
        long positionId, double stopLossPrice);

    ProtoMessage CreateAmendPositionTakeProfitRequest(long accountId,
        long positionId, double takeProfitPrice);

    ProtoMessage CreateAmendPositionSLTPRequest(long accountId,
        long positionId, double stopLossPrice, double takeProfitPrice);

    ProtoMessage CreateAmendLimitOrderRequest(long accountId, long orderId,
        double limitPrice);

    ProtoMessage CreateAmendStopOrderRequest(long accountId, long orderId,
        double stopPrice);

    ProtoMessage CreateTickDataRequest(long accountId, int symbolId, long from,
        long to, ProtoOAQuoteType type);

    ProtoOAExecutionEvent GetExecutionEvent(string msg);

    ProtoMessage CreateProtoOASymbolsListReq(long ctid);

    ProtoOASymbolsListRes GetSymbolListRes(string msg);
};

#endif // CTRADEROPENAPI_OPENAPIMESSAGEFACTORY_H

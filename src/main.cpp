#include <iostream>
#include <string>
#include "OpenApi.h"
#include "credentials.h"

using namespace std;

int main(int argc, char* argv[])
{
    OpenApi api;
    api.connect(
                "demo.ctraderapi.com",
                5035,
                CLIID,
                CLSECRET,
                ACCTOKEN,
                ACCID
            );

    api.onSymbolListReceived = [](ProtoOASymbolsListRes res) {
        for(int i = 0; i < res.symbol_size(); i++)
        {
            auto symbol = res.symbol(i);
        }
    };

    api.onAccountListReceived = [](ProtoOAGetAccountListByAccessTokenRes res) {
        for(int i = 0; i < res.ctidtraderaccount_size(); i++)
        {
            auto account = res.ctidtraderaccount(i);
        }
    };

    char opt;

    bool running = true;
    while (running) {
        cin >> opt;
        switch(opt)
        {
            case '1':
                api.authorizeApplication();
                break;
            case '2':
                api.authorizeAccount();
                break;
            case '3':
                api.getAccountsList();
                break;
            case '4':
                api.subscribeForSpots(1);
                break;
            case '5':
                api.unSubscribeFromSpots(1);
                break;
            case '6':
                api.SendLimitOrder(1, BUY, 100000,1.2001, 1.200, 1.205, 1000, "");
                break;
            case '7':
                api.ClosePosition(123121, 100000);
                break;
            case '8':
                api.GetSymbols();
                break;
            case '0':
                running = false;
                break;
            default:
                break;
        }
    }
    api.join();

    return 0;
}

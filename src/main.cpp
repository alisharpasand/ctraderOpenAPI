#include <iostream>
#include <string>
#include "OpenApi.h"
#include "credentials.h"

using namespace std;

int main(int argc, char* argv[])
{
    OpenApi api;
    api.connect(
                "live.ctraderapi.com",
                5035,
                CLIID,
                CLSECRET,
                ACCTOKEN,
                ACCID
            );

    char opt;

    bool running = true;
    while (running) {
        cout << "1- Authorize App\n2- Authorize Account\n"
        "3- Get Accounts List\n"
        "4- Subscribe For Spots\n5- Unsubscribe From Spots\n"
        "6- Market Order\n7- Close Position\n";
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
                api.subscribeForSpots();
                break;
            case '5':
                api.unSubscribeFromSpots();
                break;
            case '6':
                api.SendMarketOrder(1, BUY, 10);
                break;
            case '7':
                api.ClosePosition(123121, 100000);
                break;
            case '8':
                running = false;
                break;
            default:
                break;
        }
    }

    return 0;
}
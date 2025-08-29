
#include <iostream>
//#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsTransferScreen.h";

using namespace std;


int main()
{
    //clsMainScreen::ShowMainMenue();

    while(true)
    {
	   if (!clsLoginScreen::ShowLoginScreen())
	   {
		  break;
	   }
    }

    //clsTransferScreen::ShowTransferScreen();

    return 0;
}

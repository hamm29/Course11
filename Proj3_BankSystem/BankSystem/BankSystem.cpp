
#include <iostream>
//#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;


int main()
{
    
   /* while(true)
    {
	   if (!clsLoginScreen::ShowLoginScreen())
	   {
		  break;
	   }
    }*/

    clsTransferLogScreen::ShowTransferLogScreen();

    return 0;
}


#include <iostream>
//#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsTransferScreen.h";

using namespace std;


int main()
{
    
    while(true)
    {
	   if (!clsLoginScreen::ShowLoginScreen())
	   {
		  break;
	   }
    }


    return 0;
}

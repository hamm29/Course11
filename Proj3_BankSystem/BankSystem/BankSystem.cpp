
#include <iostream>
//#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsTransferLogScreen.h"
#include "clsCurrency.h"

using namespace std;


static void _PrintCurrency(clsCurrency Currency)
{
    cout << "\nCurrecny Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();
    cout << "\n_____________________________\n";
}

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

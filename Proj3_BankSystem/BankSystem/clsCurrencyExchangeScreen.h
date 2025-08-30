#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsMainScreen.h"


class clsCurrencyExchangeScreen : clsScreen
{

private:

    enum enCurrecnyExchangeOptions;

    //static void ShowCurrecnyExchangeMenue();
    static void _GoBackToCurrencyExchangeMainMenue()
    {
	   cout << "\nPress any key to go back to Currecny Exchange Main Menue...";
	   system("pause>0");
	   ShowCurrecnyExchangeMenue();
    }

    static short _ReadCurrecnyExchangeMenueOption()
    {
	   cout << setw(37) << left << "" << "Choose what to do from [1] to [5]: ";
	   short Choice = clsInputValidate::ReadIntNumberBetween(1, 5);
	   return Choice;
    }

    static void _ShowListCurrenciesScreen()
    {
	   cout << "\n\nThis function will be here soon!\n\n";
    }

    static void _ShowFindCurrencyScreen()
    {
	   cout << "\n\nThis function will be here soon!\n\n";
    }

    static void _ShowUpdateRateScreen()
    {
	   cout << "\n\nThis function will be here soon!\n\n";
    }

    static void _ShowCurrencyCalculatorScreen()
    {
	   cout << "\n\nThis function will be here soon!\n\n";
    }


    static void _PerformCurrencyExchangeMainMenueOptions(enCurrecnyExchangeOptions CurrecnyExchangeOptions)
    {
	   switch (CurrecnyExchangeOptions)
	   {
	   case enCurrecnyExchangeOptions::eListCurrencies:
	   {
		  system("cls");
		  _ShowListCurrenciesScreen();
		  _GoBackToCurrencyExchangeMainMenue();
		  break;
	   }
	   case enCurrecnyExchangeOptions::eFindCurrency:
	   {
		  system("cls");
		  _ShowFindCurrencyScreen();
		  _GoBackToCurrencyExchangeMainMenue();
		  break;
	   }
	   case enCurrecnyExchangeOptions::eUpdateRate:
	   {
		  system("cls");
		  _ShowUpdateRateScreen();
		  _GoBackToCurrencyExchangeMainMenue();
		  break;
	   }
	   case enCurrecnyExchangeOptions::eCurrencyCalculator:
	   {
		  system("cls");
		  _ShowCurrencyCalculatorScreen();
		  _GoBackToCurrencyExchangeMainMenue();
		  break;
	   }
	   case enCurrecnyExchangeOptions::eMainMenue:
	   {
		  
	   }
	   };
    }
public:
    enum enCurrecnyExchangeOptions
    {
	   eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
	   eCurrencyCalculator = 4, eMainMenue = 5
    };

    static void ShowCurrecnyExchangeMenue()
    {
	   system("cls");
	   _DrawScreenHeader("\tCurrecny Exchange Main Menue");
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
	   cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
	   cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
	   cout << setw(37) << left << "" << "\t[4] Currecny Calculator.\n";
	   cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
	   cout << setw(37) << left << "" << "=====================================================\n";

	   _PerformCurrencyExchangeMainMenueOptions((enCurrecnyExchangeOptions)_ReadCurrecnyExchangeMenueOption());
    }
};


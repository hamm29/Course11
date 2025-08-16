#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"

class clsTransactionsScreen : protected clsScreen
{

private:

    enum enTransactionsMenueOptions {
	   eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,
	   eMainMenue = 4
    };

    static short _ReadTransactionsMenueOptions()
    {
	   cout << setw(37) << left << "" << "Choose what to do from [1] to [4]: ";
	   short Choice = clsInputValidate::ReadIntNumberBetween(1, 4);
	   return Choice;
    }

    static void GoBackToTransactionsMenue()
    {
	   cout << "\n\nPress any key to go back to Transactions Menue...";
	   system("pause>0");
	   ShowTransactionsMenue();
    }

    static void _ShowDepositScreen()
    {
	   _DrawScreenHeader("\tDeposit Screen");

	   clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
	   //cout << "\nWithdraw Screen Will be here soon.\n";
	   clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
	   cout << "\nTotal Balances Screen Will be here soon.\n";
    }

   /* static void _ShowMainMenueScreen()
    {
	   
    }*/

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions UserChoice)
    {
	   switch (UserChoice)
	   {
	   case enTransactionsMenueOptions::eDeposit:
		  system("cls");
		  _ShowDepositScreen();
		  GoBackToTransactionsMenue();
		  break;
	   case enTransactionsMenueOptions::eWithdraw:
		  system("cls");
		  _ShowWithdrawScreen();
		  GoBackToTransactionsMenue();
		  break;
	   case enTransactionsMenueOptions::eTotalBalances:
		  system("cls");
		  _ShowTotalBalancesScreen();
		  GoBackToTransactionsMenue();
		  break;
	   case enTransactionsMenueOptions::eMainMenue:
	   {

	   }
	   }

    }


public:



    static void ShowTransactionsMenue()
    {
	   system("cls");
	   _DrawScreenHeader("\tTransactions Menue");
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t[1] Deposit.\n";
	   cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
	   cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
	   cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
	   cout << setw(37) << left << "" << "=====================================================\n";

	   _PerformTransactionsMenueOption(enTransactionsMenueOptions(_ReadTransactionsMenueOptions()));
    }



};


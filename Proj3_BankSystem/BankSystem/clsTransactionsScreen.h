#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{

private:

    enum enTransactionsMenueOptions {
	   eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,
	   eTransfer = 4, eTransferLog = 5, eMainMenue = 6
    };

    static short _ReadTransactionsMenueOptions()
    {
	   cout << setw(37) << left << "" << "Choose what to do from [1] to [6]: ";
	   short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
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
	   //cout << "\nTotal Balances Screen Will be here soon.\n";
	   clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
	   clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
	   //cout << "\n\nTransfer Log Screen will be here soon...\n\n";
	   clsTransferLogScreen::ShowTransferLogScreen();
    }

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
	   case enTransactionsMenueOptions::eTransfer:
	   {
		  system("cls");
		  _ShowTransferScreen();
		  GoBackToTransactionsMenue();
	   }
	   case enTransactionsMenueOptions::eTransferLog:
	   {
		  system("cls");
		  _ShowTransferLogScreen();
		  GoBackToTransactionsMenue();
	   }
	   case enTransactionsMenueOptions::eMainMenue:
	   {

	   }
	   }

    }


public:



    static void ShowTransactionsMenue()
    {
	   if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
	   {
		  return;
	   }

	   system("cls");
	   _DrawScreenHeader("\tTransactions Menue");
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t[1] Deposit.\n";
	   cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
	   cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
	   cout << setw(37) << left << "" << "\t[4] Transfer.\n";
	   cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
	   cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
	   cout << setw(37) << left << "" << "=====================================================\n";

	   _PerformTransactionsMenueOption(enTransactionsMenueOptions(_ReadTransactionsMenueOptions()));
    }



};


#pragma once

#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsMainScreen : protected clsScreen
{



private:
    enum enMainMenueOptions {
	   eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
	   eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
	   eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenueOptions()
    {
	   cout << setw(37) << left << "" << "Choose what to do from [1] to [8]: ";
	   short Choice = clsInputValidate::ReadIntNumberBetween(1, 8);
	   return Choice;
    }

    static void _GoBackToMainMenueScreen()
    {

	   cout << "\nPress any key to go to Main Menue...\n";
	   system("pause>0");

	   ShowMainMenue();
    }

    static void _ShowAllClientSereen()
    {
	   cout << "\nClient List will be here...\n";
    }


    static void _ShowAddNewClientSereen()
    {
	   cout << "\nAdd new Client will be here...\n";
    }

    static void _ShowDeleteClientSereen()
    {
	   cout << "\nDelete Client will be here...\n";
    }

    static void _ShowUpdateClientSereen()
    {
	   cout << "\nUpdate Client will be here...\n";
    }

    static void _ShowFindClientSereen()
    {
	   cout << "\nFind Client will be here...\n";
    }

    static void _ShowTransactionMenueSereen()
    {
	   cout << "\nTransaction Menue Screen will be here...\n";
    }

    static void _ShowManageUsersSereen()
    {
	   cout << "\nManage Users Screen will be here...\n";
    }

    static void _ShowEndSereen()
    {
	   cout << "\nEnd Screen will be here...\n";
    }

    static void _PerformMainMenueOption(enMainMenueOptions UserChoice)
    {
	   switch (UserChoice)
	   {
	   case enMainMenueOptions::eListClients:
		  system("cls");
		  _ShowAllClientSereen();
		  _GoBackToMainMenueScreen();
		  break;

	   case enMainMenueOptions::eAddNewClient:
		  system("cls");
		  _ShowAddNewClientSereen();
		  _GoBackToMainMenueScreen();
		  break;
	   case enMainMenueOptions::eDeleteClient:
		  system("cls");
		  _ShowDeleteClientSereen();
		  _GoBackToMainMenueScreen();
		  break;
	   case enMainMenueOptions::eUpdateClient:
		  system("cls");
		  _ShowUpdateClientSereen();
		  _GoBackToMainMenueScreen();
		  break;
	   case enMainMenueOptions::eFindClient:
		  system("cls");
		  _ShowFindClientSereen();
		  _GoBackToMainMenueScreen();
		  break;
	   case enMainMenueOptions::eShowTransactionsMenue:
		  system("cls");
		  _ShowTransactionMenueSereen();
		  break;
	   case enMainMenueOptions::eManageUsers:
		  system("cls");
		  _ShowManageUsersSereen();
		  break;
	   case enMainMenueOptions::eExit:
		  system("cls");
		  _ShowEndSereen();
		  break;
	   default:
		  break;
	   }

    }
    

public:

    static void ShowMainMenue()
    {
	   system("cls");
	   _DrawScreenHeader("\t\tMain Menue");
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
	   cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
	   cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
	   cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
	   cout << setw(37) << left << "" << "\t[5] Find Client.\n";
	   cout << setw(37) << left << "" << "\t[6] Transactions.\n";
	   cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
	   cout << setw(37) << left << "" << "\t[8] Logout.\n";
	   cout << setw(37) << left << "" << "=====================================================\n";

	   _PerformMainMenueOption(enMainMenueOptions(_ReadMainMenueOptions()));
    }


};


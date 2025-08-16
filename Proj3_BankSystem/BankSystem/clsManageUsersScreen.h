#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsManageUsersScreen : protected clsScreen
{
private:

    enum enManageUsersOptions
    {
	   eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
	   eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _ReadUserChoice()
    {
	   cout << setw(37) << left << "" << "Choose what to do from [1] to [6]: ";
	   short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
	   return Choice;
    }

    static void _ShowListUsersScreen()
    {
	   cout << "\nShow List User will be here.\n";
    }

    static void _ShowAddNewUsersScreen()
    {
	   cout << "\nShow Add New User will be here.\n";
    }

    static void _ShowDeleteUsersScreen()
    {
	   cout << "\nShow Delete User will be here.\n";
    }

    static void _ShowUpdateUsersScreen()
    {
	   cout << "\nShow Update User will be here.\n";
    }

    static void _ShowFindUsersScreen()
    {
	   cout << "\nShow Find User will be here.\n";
    }

    static void _GoBackToManageUsersScreen()
    {
	   cout << "\n\nPress any key to go back to Manage Users Screen.";
	   system("pause>0");
	   ShowManageUsersScreen();
    }

    static void _PerformManageUsersScreen(enManageUsersOptions UserChoice)
    {
	   //system("cls");
	   switch (UserChoice)
	   {
	   case enManageUsersOptions::eListUsers:
	   {
		  system("cls");
		  _ShowListUsersScreen();
		  _GoBackToManageUsersScreen();
		  break;
	   }
	   case enManageUsersOptions::eAddNewUser:
	   {
		  system("cls");
		  _ShowAddNewUsersScreen();
		  _GoBackToManageUsersScreen();
		  break;
	   }
	   case enManageUsersOptions::eDeleteUser:
	   {
		  system("cls");
		  _ShowDeleteUsersScreen();
		  _GoBackToManageUsersScreen();
		  break;
	   }
	   case enManageUsersOptions::eUpdateUser:
	   {
		  system("cls");
		  _ShowUpdateUsersScreen();
		  _GoBackToManageUsersScreen();
		  break;
	   }
	   case enManageUsersOptions::eFindUser:
	   {
		  system("cls");
		  _ShowFindUsersScreen();
		  _GoBackToManageUsersScreen();
		  break;
	   }
	   case enManageUsersOptions::eMainMenue:

		  break;

	   }
    }

public:

    static void ShowManageUsersScreen()
    {
	   system("cls");
	   _DrawScreenHeader("\t\tManage Users Menue");
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t\t\tManage Users Menue\n";
	   cout << setw(37) << left << "" << "=====================================================\n";
	   cout << setw(37) << left << "" << "\t[1] List Users.\n";
	   cout << setw(37) << left << "" << "\t[2] Add New Users.\n";
	   cout << setw(37) << left << "" << "\t[3] Delete Users.\n";
	   cout << setw(37) << left << "" << "\t[4] Update Users.\n";
	   cout << setw(37) << left << "" << "\t[5] Find Users.\n";
	   cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
	   cout << setw(37) << left << "" << "=====================================================\n";

	   _PerformManageUsersScreen(enManageUsersOptions(_ReadUserChoice()));
    }
};


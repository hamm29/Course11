#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{

private:

    static void _Login()
    {
	   bool LoginFaild = false;

	   string Username, Password;
	   do
	   {

		  if (LoginFaild)
		  {
			 cout << "\nInvalid Username/Password!\n\n";
		  }

		  cout << "Enter Username: ";
		  cin >> Username;

		  cout << "Enter Password: ";
		  cin >> Password;

		  CurrentUser = clsUser::Find(Username, Password);

		  LoginFaild = CurrentUser.IsEmptyMode();
	   } while (LoginFaild);

	   clsMainScreen::ShowMainMenue();
    }

public:

    static void ShowLoginScreen()
    {
	   system("cls");
	   _DrawScreenHeader("\tLogin Screen");
	   _Login();
    }
};


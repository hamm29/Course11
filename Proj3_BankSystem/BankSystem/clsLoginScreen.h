#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{

private:

    static bool _Login()
    {
	   bool LoginFaild = false;
	   short trials = 3;

	   string Username, Password;
	   do
	   {

		  if (LoginFaild)
		  {
			 trials--;
			 cout << "\nInvalid Username/Password!";
			 cout << "\nYou have " << trials << " trials to login.\n";
		  }

		  if (trials == 0)
		  {
			 cout << "\n\nYou are locked after 3 faild trials.\n";
			 return false;
		  }

		  cout << "\nEnter Username: ";
		  cin >> Username;

		  cout << "Enter Password: ";
		  cin >> Password;

		  CurrentUser = clsUser::Find(Username, Password);

		  LoginFaild = CurrentUser.IsEmptyMode();
	   } while (LoginFaild);

	   clsMainScreen::ShowMainMenue();
	   return true;
    }

public:

    static bool ShowLoginScreen()
    {
	   system("cls");
	   _DrawScreenHeader("\tLogin Screen");
	   return _Login();
    }
};


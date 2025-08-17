#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

private:

    static void _PrintUser(clsUser User)
    {
	   cout << "\nUser Card:";
	   cout << "\n___________________";
	   cout << "\nUsername   : " << User.Username;
	   cout << "\nFirstName   : " << User.FirstName;
	   cout << "\nLastName    : " << User.LastName;
	   cout << "\nFull Name   : " << User.FullName();
	   cout << "\nEmail       : " << User.Email;
	   cout << "\nPhone       : " << User.Phone;
	   cout << "\nPassword : " << User.Password;
	   cout << "\nPermissions    : " << User.Permissions;
	   cout << "\n___________________\n";
    }


public:

    static void ShowDeleteUserScreen()
    {
	   _DrawScreenHeader("\tDelete User Screen");

	   string _Username;
	   cout << "\nPlease Enter Username: ";
	   _Username = clsInputValidate::ReadString();

	   while (!clsUser::IsUserExist(_Username))
	   {
		  cout << "\nUsername is not found, Choose another one: ";
		  _Username = clsInputValidate::ReadString();
	   }

	   clsUser User = clsUser::Find(_Username);
	   _PrintUser(User);

	   char Ans = 'n';

	   cout << "Are you sure you want to delete this User? n/y? ";
	   cin >> Ans;

	   if (Ans == 'y' || Ans == 'Y')
	   {
		  if(User.Delete())
		  {
			 cout << "\nUser deleted successfully.";
			 _PrintUser(User);
		  }
		  else
		  {
			 cout << "\nError, User was not deleted.";
		  }
	   }
    }
};


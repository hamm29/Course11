#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
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

    static void ShowFindUserScreen()
    {
	   _DrawScreenHeader("\tFind User Screen");

	   cout << "\tPlease Enter Username: ";
	   string UserName = clsInputValidate::ReadString();
	   while (!clsUser::IsUserExist(UserName))
	   {
		  cout << "\nUser is not found, choose another one: ";
		  UserName = clsInputValidate::ReadString();
	   }

	   clsUser User1 = clsUser::Find(UserName);

	   if (!User1.IsEmptyMode())
	   {
		  cout << "\nUser Found :-)\n";
	   }
	   else
	   {
		  cout << "\nUser was not found :-(\n";
	   }
	   _PrintUser(User1);
    }
};


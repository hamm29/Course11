#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{

private:

    static void _ReadUserInfo(clsUser& User)
    {
	   cout << "\nEnter First Name: ";
	   User.FirstName = clsInputValidate::ReadString();

	   cout << "\nEnter Last Name: ";
	   User.LastName = clsInputValidate::ReadString();

	   cout << "\nEnter Email: ";
	   User.Email = clsInputValidate::ReadString();

	   cout << "\nEnter Phone: ";
	   User.Phone = clsInputValidate::ReadString();

	   cout << "\nEnter Password Code: ";
	   User.Password = clsInputValidate::ReadString();

	   cout << "\nEnter Permissions: ";
	   User.Permissions = ReadPermissionsToSet();
    }

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

    static int ReadPermissionsToSet()
    {
	   int Permissions = 0;
	   char Ans = 'n';

	   cout << "\nDo you want to give full access? y/n? ";
	   cin >> Ans;
	   if (Ans == 'y' || Ans == 'Y')
	   {
		  return -1;
	   }

	   cout << "\nDo you want to give access to: \n";

	   cout << "\nShow Client List? y/n? ";
	   cin >> Ans;
	   if (Ans == 'y' || Ans == 'Y')
	   {
		  Permissions += clsUser::enPermissions::pListClients;
	   }

	   cout << "\nAdd New Client ? y/n? ";
	   cin >> Ans;
	   if (Ans == 'y' || Ans == 'Y')
	   {
		  Permissions += clsUser::enPermissions::pAddNewClient;
	   }

	   cout << "\nDelete Client? y/n? ";
	   cin >> Ans;
	   if (Ans == 'y' || Ans == 'Y')
	   {
		  Permissions += clsUser::enPermissions::pDeleteClient;
	   }

	   cout << "\nUpdate Client? y/n? ";
	   cin >> Ans;
	   if (Ans == 'y' || Ans == 'Y')
	   {
		  Permissions += clsUser::enPermissions::pUpdateClients;
	   }

	   cout << "\nFind Client? y/n? ";
	   cin >> Ans;
	   if (Ans == 'y' || Ans == 'Y')
	   {
		  Permissions += clsUser::enPermissions::pFindClient;
	   }

	   cout << "\nTransactions? y/n? ";
	   cin >> Ans;
	   if (Ans == 'y' || Ans == 'Y')
	   {
		  Permissions += clsUser::enPermissions::pTranactions;
	   }

	   cout << "\nManage Users? y/n? ";
	   cin >> Ans;
	   if (Ans == 'y' || Ans == 'Y')
	   {
		  Permissions += clsUser::enPermissions::pManageUsers;
	   }

	   return Permissions;
    }

    
    public:

	   static void ShowUpdateUserScreen()
	   {
		  _DrawScreenHeader("\tUpdate User Screen");

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

		  cout << "Are you sure you want to Update this User? n/y? ";
		  cin >> Ans;

		  if (Ans == 'y' || Ans == 'Y')
		  {
			 cout << "\n\nUpdate User Info:";
			 cout << "\n______________________\n";

			 _ReadUserInfo(User);

			 clsUser::enSaveResult SaveResult;

			 SaveResult = User.Save();

			 switch (SaveResult)
			 {
			 case clsUser::enSaveResult::svSuccessful:
				cout << "\nUser Updated successfully.\n";

				_PrintUser(User);
				break;
			 case clsUser::enSaveResult::svFaildEmptyObject:
				cout << "\nError, User is empty.";
				break;
			 }
		  }
	   }
};


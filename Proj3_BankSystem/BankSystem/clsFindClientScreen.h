#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsFindClientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
	   cout << "\nClient Card:";
	   cout << "\n___________________";
	   cout << "\nFirstName   : " << Client.FirstName;
	   cout << "\nLastName    : " << Client.LastName;
	   cout << "\nFull Name   : " << Client.FullName();
	   cout << "\nEmail       : " << Client.Email;
	   cout << "\nPhone       : " << Client.Phone;
	   cout << "\nAcc. Number : " << Client.AccountNumber();
	   cout << "\nPassword    : " << Client.PinCode;
	   cout << "\nBalance     : " << Client.AccountBalance;
	   cout << "\n___________________\n";
    }


public:
    static void ShowFindClientScreen()
    {
	   if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
	   {
		  return;
	   }

	   _DrawScreenHeader("\tFind Client Screen");

	   string AccountNumber;
	   cout << "Please enter your account Number: ";
	   AccountNumber = clsInputValidate::ReadString();

	   while (!clsBankClient::IsClientExist(AccountNumber))
	   {
		  cout << "Account number is not found, try agains: ";
		  AccountNumber = clsInputValidate::ReadString();
	   }

	   clsBankClient _Client = clsBankClient::Find(AccountNumber);

	   if (!_Client.IsEmpty())
	   {
		  cout << " \nClient Found :-)\n";
	   }
	   else
	   {
		  cout << " \nClient was not Found :-)\n";
	   }

	   _PrintClient(_Client);
    }

};


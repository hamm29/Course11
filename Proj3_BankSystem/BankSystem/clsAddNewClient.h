#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>


using namespace std;

class clsAddNewClient : protected clsScreen
{

private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
	   cout << "\nEnter First Name: ";
	   Client.FirstName = clsInputValidate::ReadString();

	   cout << "\nEnter Last Name: ";
	   Client.LastName = clsInputValidate::ReadString();

	   cout << "\nEnter Email: ";
	   Client.Email = clsInputValidate::ReadString();

	   cout << "\nEnter Phone: ";
	   Client.Phone = clsInputValidate::ReadString();

	   cout << "\nEnter Pin Code: ";
	   Client.PinCode = clsInputValidate::ReadString();

	   cout << "\nEnter Account Balance: ";
	   Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

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

    static void ShowAddNewClientScreen()
    {

	   if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
	   {
		  return;
	   }

	   _DrawScreenHeader("\tAdd New Client Screen");

	   string AccountNumber = "";

	   cout << "\nPlease enter Acount Number: ";
	   AccountNumber = clsInputValidate::ReadString();
	   while (clsBankClient::IsClientExist(AccountNumber))
	   {
		  cout << "\nAccount Number is already Used, Choose another one: ";
		  AccountNumber = clsInputValidate::ReadString();
	   }

	   clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	   _ReadClientInfo(NewClient);

	   clsBankClient::enSaveResults SaveResult;

	   SaveResult = NewClient.Save();

	   switch (SaveResult)
	   {
	   case clsBankClient::enSaveResults::svSucceeded:
		  cout << "\nAccount Added Successfully :-)\n";
		  _PrintClient(NewClient);
		  break;
	   case clsBankClient::enSaveResults::svFaildEmptyObject:
		  cout << "\nError, Account was not saved because it's Empty.";
		  break;
	   case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		  cout << "\nAccount Number is already Used, Choose another one: ";
		  break;
	   }

    }

};


#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsWithdrawScreen : protected clsScreen
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

    static void ShowWithdrawScreen()
    {
	   _DrawScreenHeader("\tWithdraw Screen");

	   cout << "\nEnter Account Number: ";
	   string AccountNumber = clsInputValidate::ReadString();

	   while (!clsBankClient::IsClientExist(AccountNumber))
	   {
		  cout << "\nAccount Number is not found, try again: ";
		  AccountNumber = clsInputValidate::ReadString();
	   }

	   clsBankClient Client = clsBankClient::Find(AccountNumber);

	   _PrintClient(Client);

	   float Amount = 0;
	   cout << "\nEnter Withdraw amount: ";
	   Amount = clsInputValidate::ReadFloatNumber();

	   char Ans = 'n';
	   cout << "\nAre sure you want to perform this transactions? y/n? ";
	   cin >> Ans;

	   if (Ans == 'y' || Ans == 'Y')
	   {
		  if (Client.Withdraw(Amount))
		  {
			 cout << "\nAmount Withdraw successfully.\n";
			 cout << "\nNew Balance is: " << Client.AccountBalance;
		  }
		  else
		  {
			 cout << "\nCannot Withdraw, Insuffecient Balance.\n";
			 cout << "\nAmount to Withdraw is: \n" << Amount;
			 cout << "\nYour Balance is: " << Client.AccountBalance;
		  }
	   }
	   else
	   {
		  cout << "\n\nOperation was cancelled.\n\n";
	   }
    }

};


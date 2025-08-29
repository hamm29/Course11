#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"


class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClientCard(clsBankClient Client)
    {
	   cout << "\nClient Card:";
	   cout << "\n------------------------";
	   cout << "\nFull Name   : " << Client.FullName();
	   cout << "\nAcc. Number : " << Client.AccountNumber();
	   cout << "\nBalance     : " << Client.AccountBalance;
	   cout << "\n------------------------\n";

    }

    static string _ReadAccountNumber()
    {
	   string AccountNumber;
	   cout << "\nPlease Enter Account Number to Transfer From: ";
	   AccountNumber = clsInputValidate::ReadString();
	   while (!clsBankClient::IsClientExist(AccountNumber))
	   {
		  cout << "\nThe Account Number is not found, choose another one: ";
		  AccountNumber = clsInputValidate::ReadString();
	   }
	   return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourcClient)
    {
	   float Amount;

	   cout << "\nEnter Transfer Amount? ";
	   Amount = clsInputValidate::ReadFloatNumber();

	   while (Amount > SourcClient.AccountBalance)
	   {
		  cout << "\nAmount Exceeds the available Balance, Enter another amount: ";
		  Amount = clsInputValidate::ReadFloatNumber();
	   }
	   return Amount;
    }

public:

    static void ShowTransferScreen()
    {

	   _DrawScreenHeader("\t  Transfer Screen");

	   bool EmptyClient = false;
	   string AccTransferFrom = "";

	   clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
	   _PrintClientCard(SourceClient);

	   clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
	   _PrintClientCard(DestinationClient);

	   float Amount = _ReadAmount(SourceClient);

	   cout << "\nAre you sure you want to perform this operation? y/n? ";
	   char Answer = 'n';
	   cin >> Answer;

	   if (Answer == 'y' || Answer == 'Y')
	   {
		  if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.Username))
		  {
			 cout << "\nTransfer done successfully\n";
		  }
		  else
		  {
			 cout << "\nTransfer Faild\n";
		  }
	   }
	   else
	   {
		  cout << "\n\n Operation was cancalled!\n\n";
	   }

	   _PrintClientCard(SourceClient);
	   _PrintClientCard(DestinationClient);

    }

};


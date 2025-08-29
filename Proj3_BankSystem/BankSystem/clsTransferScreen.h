#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsBankClient.h"


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

public:

    static void ShowTransferScreen()
    {

	   _DrawScreenHeader("\t  Transfer Screen");

	   bool EmptyClient = false;
	   string AccTransferFrom = "";
	   clsBankClient Client1 = clsBankClient::GetAddNewClientObject("");

	   do
	   {
		  if (EmptyClient)
		  {
			 cout << "\nThe Account Number is not found! Try Again.";
		  }
		  cout << "\nPlease Enter Account Number to Transfer From: ";
		  cin >> AccTransferFrom;
		  Client1 = clsBankClient::Find(AccTransferFrom);
		  EmptyClient = Client1.IsEmpty();
	   } while (EmptyClient);
	   _PrintClientCard(Client1);


	   EmptyClient = false;
	   string AccTransferTo = "";
	   clsBankClient Client2 = clsBankClient::GetAddNewClientObject("");

	   do
	   {
		  if (EmptyClient)
		  {
			 cout << "\nThe Account Number is not found! Try Again.";
		  }
		  cout << "\nPlease Enter Account Number to Transfer To: ";
		  cin >> AccTransferTo;
		  Client2 = clsBankClient::Find(AccTransferTo);
		  EmptyClient = Client2.IsEmpty();
	   } while (EmptyClient);
	   _PrintClientCard(Client2);

	   float Amount = 0;
	   cout << "\n\nEnter Transfer Amount? ";
	   cin >> Amount;
	   bool AmountExceedsBalance = Amount > Client1.AccountBalance;
	   char Conformation = 'n';

	   while (AmountExceedsBalance)
	   {
		  cout << "Amount Exceeds the available Balance, Enter another amount? ";
		  cin >> Amount;
		  AmountExceedsBalance = Amount > Client1.AccountBalance;
	   }
	   cout << "\nAre you sure you want to perform this operation? y/n? ";
	   cin >> Conformation;
	   if (Conformation == 'y' || Conformation == 'Y')
	   {
		  Client1.Withdraw(Amount);
		  Client2.Deposit(Amount);

		  cout << "\n\nTransfer done successfully!\n";
		  _PrintClientCard(Client1);
		  _PrintClientCard(Client2);
	   }
	   else
	   {
		  cout << "\n\nOperation was cancalled!\n\n";
	   }


    }

};


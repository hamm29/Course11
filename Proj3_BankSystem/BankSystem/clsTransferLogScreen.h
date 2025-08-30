#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsBankClient.h"
#include "clsString.h"

class clsTransferLogScreen : protected clsScreen
{

private:
    struct stTransferLogRegister;

    static void _PrintTransferLogLine(clsBankClient::stTransferLogRecord LogRegister)
    {
	   
	   cout << "\t| " << setw(20) << left << LogRegister.Date;
	   cout << "| " << setw(10) << left << LogRegister.SourceAccountNumber;
	   cout << "| " << setw(10) << left << LogRegister.DestinationAccountNumber;
	   cout << "| " << setw(10) << left << LogRegister.Amount;
	   cout << "| " << setw(12) << left << LogRegister.srcBalanceAfter;
	   cout << "| " << setw(12) << left << LogRegister.destBalanceAfter;
	   cout << "| " << setw(10) << left << LogRegister.UserName;
    }

public:

    

    static void ShowTransferLogScreen()
    {
	   vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();
	   string Title = "\t  Transfer Log List Screen ";
	   string SubTitle = "\t  ()" " Record(s).";
	   _DrawScreenHeader(Title, SubTitle);

	   cout << "\n\n\t-------------------------------------------------";
	   cout << "-------------------------------------------------\n";
	   cout << "\t| " << setw(20) << left << "Date/Time";
	   cout << "| " << setw(10) << left << "s.Acct";
	   cout << "| " << setw(10) << left << "d.Acct";
	   cout << "| " << setw(10) << left << "Amount";
	   cout << "| " << setw(12) << left << "s.Balance";
	   cout << "| " << setw(12) << left << "d.Balance";
	   cout << "| " << setw(10) << left << "User";
	   cout << "\n\t-------------------------------------------------";
	   cout << "-------------------------------------------------\n";

	   if (vTransferLogRecord.size() == 0)
		  cout << "\t\t\t\tNot Transfer Available In the system!";
	   else
	   {
		  for (clsBankClient::stTransferLogRecord R : vTransferLogRecord)
		  {
			 _PrintTransferLogLine(R);
			 cout << endl;
		  }
	   }

	   cout << "\t-------------------------------------------------";
	   cout << "-------------------------------------------------\n";

    }
};


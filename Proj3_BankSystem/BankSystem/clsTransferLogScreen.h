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

    static void _PrintTransferLogLine()
    {

    }

    vector <string> _ConvertDataLineToVector(string line)
    {
	   vector <string> vTransferLogReg = clsString::Split(line, "#//#");
	   
	   return vTransferLogReg;
    }

public:

    struct stTransferLogRegister
    {
	   string Date;
	   string sAcct;
	   string dAcct;
	   float Amount;
	   float sBalance;
	   float dBalance;
	   string User;
    };

    static void ShowTransferLogScreen()
    {
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


	   cout << "\n\n\n\n";

	   cout << "\n\n\t-------------------------------------------------";
	   cout << "-------------------------------------------------\n";

	   cout << "\t\n\nTransfer Log Screen will be here soon...\n\n";
    }
};


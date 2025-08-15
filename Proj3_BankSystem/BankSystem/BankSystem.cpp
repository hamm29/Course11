
#include <iostream>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsPerson.h"
#include <iomanip>
#include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;


void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
	   cout << "\nAccount number is not found, choose another one: ";
	   AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info: ";
    cout << "\n______________________________\n";

    //ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:

	   cout << "\nAccount Updated Successfully :-)\n";
	   Client1.Print();
	   break;
    case clsBankClient::enSaveResults::svFaildEmptyObject:
	   cout << "\nError account was not saved because it's Empty";
	   break;
    }

}

void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    

}

void DeleteClient()
{
    
}



void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(40) << Client.FullName();
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    cout << "\n\t\t\t\tBalance List (" << vClients.size() << ") Client(s)";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalance = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
    {
	   cout << "\t\t\tNo Clients Available In the System!";
    }
    else
    {
	   for (clsBankClient& Client : vClients)
	   {
		  PrintClientRecordBalanceLine(Client);
		  cout << endl;
	   }
    }

    cout << "_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "\t\t\tTotal Balance = " << TotalBalance;
    cout << "\n\t\t(" << clsUtil::NumberToText(TotalBalance) << ")\n";

}



int main()
{
    clsMainScreen::ShowMainMenue();
    system("pause>0");
    return 0;
}

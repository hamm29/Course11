
#include <iostream>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsPerson.h"
#include <iomanip>
#include "clsUtil.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
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

    ReadClientInfo(Client1);

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
    while (clsBankClient::IsClientExist(AccountNumber))
    {
	   cout << "\nAccount Number is already Used, Choose another one: ";
	   AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
	   cout << "\nAccount Added Successfully :-)\n";
	   NewClient.Print();
	   break;
    case clsBankClient::enSaveResults::svFaildEmptyObject:
	   cout << "\nError, Account was not saved because it's Empty.";
	   break;
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
	   cout << "\nAccount Number is already Used, Choose another one: ";
	   break;
    }

}

void DeleteClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
	   cout << "\nAccount number is not found, choose another one: ";
	   AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\nAre you sure you want to delete this client y/n? ";

    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {


	   if (Client1.Delete())
	   {
		  cout << "\nClient Deleted Successfully :-)\n";

		  Client1.Print();
	   }
	   else
	   {
		  cout << "\nError Client Was not Deleted\n";
	   }
    }
}

void PrintClientRecordLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(20) << left << Client.Email;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowClientsList()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
	   cout << "\t\t\t\tNo Clients Available In the System!";
    else

	   for (clsBankClient Client : vClients)
	   {

		  PrintClientRecordLine(Client);
		  cout << endl;
	   }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

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
    ShowTotalBalances();
    system("pause>0");
    return 0;
}

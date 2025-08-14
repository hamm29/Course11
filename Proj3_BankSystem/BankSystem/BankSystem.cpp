
#include <iostream>
#include "clsBankClient.h";
#include "clsInputValidate.h"

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

using namespace std;

int main()
{

    AddNewClient();

    system("pause>0");

}

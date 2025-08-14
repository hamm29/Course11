#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;

    static clsBankClient _ConverLineToClientObject(string line, string seperator = "#//#")
    {
	   vector <string> vClient = clsString::Split(line, seperator);

	   return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2],
		  vClient[3], vClient[4], vClient[5], stof(vClient[6]));
    }

    static clsBankClient _GetEmptyClient()
    {
	   return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector <clsBankClient> _LoadClientsDataFromFile()
    {
	   vector <clsBankClient> _vClients;

	   fstream myFile;

	   myFile.open("Clients.txt", ios::in);

	   if (myFile.is_open())
	   {
		  string line;
		  while (getline(myFile, line))
		  {
			 _vClients.push_back(_ConverLineToClientObject(line));
		  }
		  myFile.close();
	   }
	   return _vClients;
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
	   string stClientRecord = "";
	   stClientRecord = Client.FirstName + Seperator;
	   stClientRecord = Client.LastName + Seperator;
	   stClientRecord = Client.Email + Seperator;
	   stClientRecord = Client.Phone + Seperator;
	   stClientRecord = Client.AccountNumber() + Seperator;
	   stClientRecord = Client.PinCode + Seperator;
	   stClientRecord = to_string(Client.AccountBalance) + Seperator;

	   return stClientRecord;
    }

    static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
    {

	   fstream myFile; 

	   myFile.open("Clients.txt", ios::out);

	   if (myFile.is_open())
	   {
		  string line;
		  for (clsBankClient& C : vClients)
		  {
			 line = _ConvertClientObjectToLine(C);
			 myFile << line << endl;
		  }
		  myFile.close();
	   }

    }

    void _Update()
    {
	   vector <clsBankClient> _vClients;
	   _vClients = _LoadClientsDataFromFile();

	   for (clsBankClient& C : _vClients)
	   {
		  if (C.AccountNumber() == AccountNumber())
		  {
			 C = *this;
			 break;
		  }
	   }
	   _SaveClientsDataToFile(_vClients);
    }

    void _AddDataLineToFile(string line)
    {
	   fstream myFile;

	   myFile.open("Clients.txt", ios::out | ios::app);

	   if (myFile.is_open())
	   {
		  string DateLine = line;
		  myFile << DateLine << endl;

		  myFile.close();
	   }
    }

    void _AddNew()
    {
	   _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

public:

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
	   string AccountNumber, string PinCode, float AccountBalance) :
	   clsPerson(FirstName, LastName, Email, Phone)
    {
	   _Mode = Mode;
	   _AccountNumber = AccountNumber;
	   _PinCode = PinCode;
	   _AccountBalance = AccountBalance;
    }

    string AccountNumber()
    {
	   return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
	   _PinCode = PinCode;
    }

    string GetPinCode()
    {
	   return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
	   _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
	   return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    bool IsEmpty()
    {
	   return (_Mode == enMode::EmptyMode);
    }

    void Print()
    {
	   cout << "\nClient Card:";
	   cout << "\n___________________";
	   cout << "\nFirstName   : " << FirstName;
	   cout << "\nLastName    : " << LastName;
	   cout << "\nFull Name   : " << FullName();
	   cout << "\nEmail       : " << Email;
	   cout << "\nPhone       : " << Phone;
	   cout << "\nAcc. Number : " << _AccountNumber;
	   cout << "\nPassword    : " << _PinCode;
	   cout << "\nBalance     : " << _AccountBalance;
	   cout << "\n___________________\n";
    }

    static clsBankClient Find(string AccountNumber)
    {
	   vector <clsBankClient> vBankClients;

	   fstream myFile;

	   myFile.open("Clients.txt", ios::in);

	   if (myFile.is_open())
	   {
		  string line;
		  while (getline(myFile, line))
		  {
			 clsBankClient Client = _ConverLineToClientObject(line, "#//#");
			 if (Client.AccountNumber() == AccountNumber)
			 {
				return Client;
				myFile.close();
			 }
		  }
		  myFile.close();
	   }
	   return _GetEmptyClient();
    }
   
    static clsBankClient Find(string AccountNumber, string PinCode)
    {
	   vector <clsBankClient> vBankClients;

	   fstream myFile;

	   myFile.open("Clients.txt", ios::in);

	   if (myFile.is_open())
	   {
		  string line;
		  while (getline(myFile, line))
		  {
			 clsBankClient Client = _ConverLineToClientObject(line, "#//#");
			 if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
			 {
				return Client;
				myFile.close();
			 }
		  }
		  myFile.close();
	   }
	   return _GetEmptyClient();
    }

    static bool IsClientExist(string AccountNumber)
    {
	   clsBankClient Client = Find(AccountNumber);

	   return (!Client.IsEmpty());
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults Save()
    {
	   switch (_Mode)
	   {
	   case enMode::EmptyMode:
	   {
		  return enSaveResults::svFaildEmptyObject;
	   }
	   case enMode::UpdateMode:
	   {
		  _Update();
		  return enSaveResults::svSucceeded;

		  break;
	   }
	   case enMode::AddNewMode:

		  if (clsBankClient::IsClientExist(AccountNumber()))
		  {
			 return enSaveResults::svFaildAccountNumberExists;
		  }
		  else
		  {
			 _AddNew();

			 _Mode = enMode::UpdateMode;
			 return enSaveResults::svSucceeded;
		  }
		  
	   }
	   
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
	   return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

};


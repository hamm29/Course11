#pragma once

#include <iostream>
#include <vector>
#include "clsPerson.h"
#include <fstream>
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;


class clsUser : public clsPerson
{
private:

    enum enMode
    {
	   EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
    };
    enMode _Mode;
    string _Username;
    string _Password;
    string _EncryptedPassword;
    int _Permissions;

    bool _MarkedForDelete = false;

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string stUserRecord = "";
        stUserRecord += User.FirstName + Seperator;
        stUserRecord += User.LastName + Seperator;
        stUserRecord += User.Email + Seperator;
        stUserRecord += User.Phone + Seperator;
        stUserRecord += User.Username + Seperator;
        stUserRecord += clsUtil::EncryptText(User.Password) + Seperator;
        stUserRecord += to_string(User.Permissions);

        return stUserRecord;
    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;
            
            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);
                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

    }

    string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRegisterLine = "";
        LoginRegisterLine = clsDate::GetSystemDateTimeString() + Seperator;
        LoginRegisterLine += Username + Seperator;
        LoginRegisterLine += clsUtil::EncryptText(Password) + Seperator;
        LoginRegisterLine += to_string(Permissions);

        return LoginRegisterLine;
    }

    
    struct stLoginRegisterRecord;
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;

        vector <string> LoginRegisterLine = clsString::Split(Line, Seperator);

        LoginRegisterRecord.DateTime = LoginRegisterLine[0];
        LoginRegisterRecord.UserName = LoginRegisterLine[1];
        LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterLine[3]);

        return LoginRegisterRecord;
    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.Username == _Username)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);
    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static string EnctyptedPassword(string Password)
    {
        return clsUtil::EncryptText(Password);
    }
    

public:


    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;
    };

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
	   string Username, string Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
    {
	   _Mode = Mode;
	   _Username = Username;
	   _Password = Password;
	   _Permissions = Permissions;
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    bool IsEmptyMode()
    {
	   return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDelete()
    {
	   return (_MarkedForDelete);
    }

    void SetUsername(string Username)
    {
	   _Username = Username;
    }

    string GetUsername()
    {
	   return _Username;
    }
    __declspec(property(get = GetUsername, put = SetUsername)) string Username;

    void SetPassword(string Password)
    {
	   _Password = Password;
    }

    string GetPassword()
    {
	   return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
	   _Permissions = Permissions;
    }

    int GetPermissions()
    {
	   return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string Username)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.Username == Username)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(string Username, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.Username == Username && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static bool IsUserExist(string Username)
    {
        clsUser User = clsUser::Find(Username);
        return (!User.IsEmptyMode());
    }

    enum enSaveResult { svFaildEmptyObject = 0, svSuccessful = 1, svFaildUsernameExists = 3 };

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResult::svFaildEmptyObject;

        case enMode::UpdateMode:
            
            _Update();
            return enSaveResult::svSuccessful;
        case enMode::AddNewMode:

            if (clsUser::IsUserExist(_Username))
            {
                return enSaveResult::svFaildUsernameExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResult::svSuccessful;
            }
        }
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.Username == _Username)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string Username)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
    }


    static vector <clsUser> GetUserList()
    {
        return _LoadUsersDataFromFile();
    }

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,
        pLoginRegisterList = 128
    };


    bool ShowAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == -1)
            return true;

        if ((Permission & this->Permissions) == Permission)
        {
            return true;
        }
        else
            return false;
    }

    void RegisterLogin()
    {
        string stDataLine = _PrepareLogInRecord();

        fstream myFile;
        myFile.open("LoginRegister.txt", ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << stDataLine << endl;

            myFile.close();
        }
    }

    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {
                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);
            }

            MyFile.close();
        }
        return vLoginRegisterRecord;
    }

};


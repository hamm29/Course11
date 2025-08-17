#pragma once

#include <iostream>
#include <vector>
#include "clsPerson.h"
#include <fstream>
#include "clsString.h"

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
        stUserRecord += User.Password + Seperator;
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

    static clsUser _ConvertLinetoUserObject(string DateLine)
    {
        vector <string >vUser = clsString::Split(DateLine, "#//#");

        return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2],
            vUser[3], vUser[4], vUser[5], stoi(vUser[6]));
    }

    

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

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

public:

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
	   return (_Mode = enMode::EmptyMode);
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
};


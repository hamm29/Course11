#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <vector>
#include <iomanip>


class clsLoginRegisterScreen : protected clsScreen
{
private:

    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
	   cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRegisterRecord.DateTime;
	   cout << "| " << left << setw(25) << LoginRegisterRecord.UserName;
	   cout << "| " << left << setw(17) << LoginRegisterRecord.Password;
	   cout << "| " << left << setw(12) << LoginRegisterRecord.Permissions;
    }


public:
    
    static void ShowLoginRegisterScreen()
    {

	   if (!CheckAccessRights(clsUser::enPermissions::pLoginRegisterList))
	   {
		  return;
	   }

	   vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
	    
	   string Title = "\t  Login Register List Screen";
	   string SubTitle = "\t\t( " + to_string(vLoginRegisterRecord.size()) + ") Register(s)";
	   _DrawScreenHeader(Title);

	   cout << setw(8) << left << "" << "\n\t_________________________________________________";
	   cout << "_____________________________________________________\n";

	   cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
	   cout << "| " << left << setw(25) << "UserName";
	   cout << "| " << left << setw(17) << "Password";
	   cout << "| " << left << setw(12) << "Permissions";
	   cout << setw(8) << left << "\n\t_________________________________________________";
	   cout << "_____________________________________________________\n";

	   if (vLoginRegisterRecord.size() == 0)
	   {
		  cout << "There is no User...";
	   }
	   else
	   {
		  for (clsUser::stLoginRegisterRecord& User : vLoginRegisterRecord)
		  {
			 PrintLoginRegisterRecordLine(User);
			 cout << endl;
		  }
	   }

	   cout << setw(8) << left << "\n\t_________________________________________________";
	   cout << "_____________________________________________________";
    }
};


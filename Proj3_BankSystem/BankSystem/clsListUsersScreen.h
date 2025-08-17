#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>



class clsListUsersScreen : protected clsScreen
{
private :

    static void _PrintUserRecordLine(clsUser User)
    {
	   cout << setw(8) << left << "" << "| " << left << setw(12) << User.Username;
	   cout << "| " << setw(25) << left << User.FullName();
	   cout << "| " << setw(12) << left << User.Phone;
	   cout << "| " << setw(20) << left << User.Email;
	   cout << "| " << setw(10) << left << User.Password;
	   cout << "| " << setw(12) << left << User.Permissions;
    }

public :
    
    static void ShowUsersList()
    {
	   vector <clsUser> vUsers = clsUser::GetUserList();

	   string Title = "\tUser List Screen.";
	   string SubTitle = "\t  (" + to_string(vUsers.size()) + ") Users(s)";
	   _DrawScreenHeader(Title, SubTitle);

	   cout << setw(8) << left << "" << "\n\t_________________________________________________";
	   cout << "_____________________________________________________\n";

	   cout << setw(8) << left << "" << "| " << left << setw(12) << "Username";
	   cout << "| " << left << setw(25) << "Full Name";
	   cout << "| " << left << setw(12) << "Phone";
	   cout << "| " << left << setw(20) << "Email";
	   cout << "| " << left << setw(10) << "Password";
	   cout << "| " << left << setw(12) << "Permissions";
	   cout << setw(8) << left << "\n\t_________________________________________________";
	   cout << "_____________________________________________________\n";

	   if (vUsers.size() == 0)
	   {
		  cout << "There is no User...";
	   }
	   else
	   {
		  for (clsUser& User : vUsers)
		  {
			 _PrintUserRecordLine(User);
			 cout << endl;
		  }
	   }

	   cout << setw(8) << left << "\n\t_________________________________________________";
	   cout << "_____________________________________________________";
    }

};


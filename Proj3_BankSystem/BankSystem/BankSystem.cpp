
#include <iostream>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsPerson.h"
#include <iomanip>
#include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;


void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    

}






int main()
{
    clsMainScreen::ShowMainMenue();
    system("pause>0");
    return 0;
}

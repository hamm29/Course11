
#include <iostream>
#include "clsInputValidate.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
    cout << clsInputValidate::IsNumberBetween(10, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(8, 8, 2025), clsDate(8, 12, 2025)) << endl;
    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(8, 12, 2025), clsDate(8, 8, 2025)) << endl;
    

    /*cout << "\nPlease Enter a number: ";
    int x = clsInputValidate::ReadIntNumber("\nInvalid Number, Enter Again: ");
    cout << "\nx = " << x;*/

    cout << "\nPlease Enter a Number between 1 and 5: \n";
    int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number in not within rang, try again: ");
    cout << "y = " << y;

    cout << "\nPlease Enter a Double Number between 1 and 5: \n";
    double d = clsInputValidate::ReadDoubleNumberBetween(1.3, 6.3, "Number in not within rang, try again: ");
    cout << "d = " << d;
    system("pause>0");

    cout << endl;
    cout << clsInputValidate::IsValidDate(clsDate(30, 12, 2022)) << endl;
}


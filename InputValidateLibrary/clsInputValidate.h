#pragma once

#include <iostream>
#include "clsDate.h"

using namespace std;


class clsInputValidate
{

public:

    static bool IsNumberBetween(double Number, double From, double To)
    {
	   return Number >= From ? (Number <= To ? true : false) : false;
    }

    static bool IsNumberBetween(int& Number, int& From, int& To)
    {
	   return IsNumberBetween(Number, From, To);
    }


    static bool IsDateBetween(clsDate currentDate, clsDate Start, clsDate End)
    {
	   if (clsDate::IsDate1BeforeDate2(Start, currentDate))
	   {
		  if (clsDate::IsDate1BeforeDate2(currentDate, Start) || clsDate::IsDate1AfterDate2(currentDate, End))
			 return false;
		  else
			 return true;
	   }
	   else
	   {
		  if (clsDate::IsDate1BeforeDate2(currentDate, End) || clsDate::IsDate1AfterDate2(currentDate, Start))
			 return false;
		  else
			 return true;
	   }
    }

    //something wrong************
    static int ReadIntNumber(string Message)
    {
	   int x;

	   
	   /*while (x == 0)
	   {
		  
		  cin >> x;
	   }*/

	   do
	   {
		  cin >> x;
		  if (x == 0)
			 cout << Message;

	   } while (x == 0);

	   return x;
    }




    static float ReadDoubleNumberBetween(float from, float to, string Message)
    {
	   float c;

	   cin >> c;

	   while (c < from || c > to)
	   {
		  cout << Message;
		  cin >> c;
	   }
	   return c;
    }

    static int ReadIntNumberBetween(int from, int to, string Message)
    {
	   return ReadDoubleNumberBetween(from, to, Message);
    }

    static bool IsValidDate(clsDate Date)
    {
	   return clsDate::IsValidDate(Date);
    }



};


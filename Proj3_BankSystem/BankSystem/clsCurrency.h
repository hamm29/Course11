#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"


class clsCurrency
{

private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLinetoCurrencyObject(string line)
    {
	   vector <string> vLine = clsString::Split(line, "#//#");
	   // There would be something wrong!
	   return clsCurrency(enMode::UpdateMode, vLine[0], vLine[1], vLine[2], stof(vLine[3]));

    }

    static vector <clsCurrency> _LoadCurrencyDataFromFile()
    {
	   vector <clsCurrency> vCurrenciesList;

	   fstream MyFile;

	   MyFile.open("Currencies.txt", ios::in);

	   if (MyFile.is_open())
	   {
		  string Line;
		  
		  while (getline(MyFile, Line))
		  {
			 clsCurrency C = _ConvertLinetoCurrencyObject(Line);
			 
			 vCurrenciesList.push_back(C);
		  }
		  MyFile.close();
	   }
	   return vCurrenciesList;
    }

    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {
	   string stCurrencyRecord = "";
	   stCurrencyRecord += Currency.Country() + Seperator;
	   stCurrencyRecord += Currency.CurrencyCode() + Seperator;
	   stCurrencyRecord += Currency.CurrencyName() + Seperator;
	   stCurrencyRecord += to_string(Currency.Rate());

	   return stCurrencyRecord;
    }

    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrenciesList)
    {
	   //Stopped here ************
	   fstream MyFile;

	   MyFile.open("Currencies.txt", ios::out | ios::app);

	   if (MyFile.is_open())
	   {
		  string Line;
		  for (clsCurrency& C : vCurrenciesList)
		  {
			 Line = _ConverCurrencyObjectToLine(C);
			 MyFile << Line << endl;
		  }
		  MyFile.close();
	   }
    }

    void _Update()
    {
	   vector <clsCurrency> vCurrenciesList = _LoadCurrencyDataFromFile();

	   for (clsCurrency& C : vCurrenciesList)
	   {
		  if (C.CurrencyCode() == CurrencyCode())
		  {
			 C = *this;
			 break;
		  }
	   }
	   _SaveCurrencyDataToFile(vCurrenciesList);
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
	   return clsCurrency(clsCurrency::enMode::EmptyMode, "", "", "", 0);
    }

public :

    clsCurrency(enMode Mode, string Country, string CurrecnyCode,
	   string CurrencyName, float Rate)
    {
	   _Mode = Mode;
	   _Country = Country;
	   _CurrencyCode = CurrecnyCode;
	   _CurrencyName = CurrencyName;
	   _Rate = Rate;
    }

    static vector <clsCurrency> GetAllUSDRates()
    {
	   return _LoadCurrencyDataFromFile();
    }

    bool IsEmpty()
    {
	   return _Mode = EmptyMode;
    }

    string Country()
    {
	   return _Country;
    }

    string CurrencyCode()
    {
	   return _CurrencyCode;
    }

    string CurrencyName()
    {
	   return _CurrencyName;
    }

    void UpdateRate(float NewRate)
    {
	   _Rate = NewRate;
	   _Update();
    }

    float Rate()
    {
	   return _Rate;
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {
	   CurrencyCode = clsString::UpperAllString(CurrencyCode);

	   fstream MyFile;
	   MyFile.open("Currencies.txt", ios::in);//read Mode

	   if (MyFile.is_open())
	   {
		  string Line;
		  while (getline(MyFile, Line))
		  {
			 clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
			 if (Currency.CurrencyCode() == CurrencyCode)
			 {
				MyFile.close();
				return Currency;
			 }
		  }

		  MyFile.close();

	   }

	   return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country)
    {
	   Country = clsString::UpperAllString(Country);

	   fstream MyFile;
	   MyFile.open("Currencies.txt", ios::in);//read Mode

	   if (MyFile.is_open())
	   {
		  string Line;
		  while (getline(MyFile, Line))
		  {
			 clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
			 if (clsString::UpperAllString(Currency.Country()) == Country)
			 {
				MyFile.close();
				return Currency;
			 }

		  }

		  MyFile.close();

	   }

	   return _GetEmptyCurrencyObject();

    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
	   clsCurrency C = FindByCode(CurrencyCode);
	   return (!C.IsEmpty());
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
	   vector <clsCurrency> CurrenciesList = _LoadCurrencyDataFromFile();

	   return CurrenciesList;
    }


};


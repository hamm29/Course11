#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class clsUtil
{

public:
    enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }


    static int RandomNumber(int From, int To)
    {
        // Generate a random number between 0 and (To - From), then add From to shift the range.
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            // Generate a random lowercase letter (ASCII: 97 'a' to 122 'z').
            return char(RandomNumber(97, 122));
            break; // break is not necessary after return.
        }
        case enCharType::CapitalLetter:
        {
            // Generate a random uppercase letter (ASCII: 65 'A' to 90 'Z').
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            // Generate a random special character (ASCII: 33 '!' to 47 '/').
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            // Generate a random digit (ASCII: 48 '0' to 57 '9').
            return char(RandomNumber(48, 57));
            break;
        }
        }
        // If no valid type is provided, return a null character.
        return '\0';
    }

    static int ReadPositiveNumber(string Message)
    {
        int Number = 0;  // Variable to store the user's input.
        do
        {
            cout << Message << endl; // Display the prompt message.
            cin >> Number;           // Read the number from the user.
        } while (Number <= 0);       // Continue prompting until a positive number is entered.
        return Number;
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;  // Initialize an empty string to build the word.

        // Loop for the number of characters specified by Length.
        for (int i = 1; i <= Length; i++)
        {
            // Append a random character of the specified type to the word.
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey()
    {
        string Key = "";  // Initialize an empty key string.

        // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys)
    {
        // Loop from 1 to NumberOfKeys.
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            // Print the current key number and the generated key.
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }
    }


};


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

    static void ReadArray(int arr[100], int& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;  // Read the total number of elements the user wishes to input.

        cout << "\nEnter array elements: \n";
        // Loop from 0 to arrLength - 1 to read each array element.
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";  // Display a prompt for each element (using 1-based indexing for clarity).
            cin >> arr[i];                           // Read the current element into the array.
        }
        cout << endl;  // Print an extra newline for formatting.
    }

    static void PrintArray(int arr[100], int arrLength)
    {
        // Loop through the array and print each element followed by a space.
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << " ";

        cout << "\n";  // Print a newline after all elements are printed.
    }

    static int TimesRepeated(int Number, int arr[100], int arrLength)
    {
        int count = 0;  // Initialize a counter to zero.
        // Loop through the array indices from 0 to arrLength - 1.
        for (int i = 0; i <= arrLength - 1; i++)
        {
            if (Number == arr[i])  // If the current element equals the number we're checking,
            {
                count++;  // Increment the counter.
            }
        }
        return count;  // Return the total count.
    }

    static void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;  // Read the desired number of elements from the user.

        // Fill the array with random numbers between 1 and 100.
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }

    static int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;  // Initialize Max to 0. (Note: This assumes array elements are positive.)

        // Loop through the array to find the maximum element.
        for (int i = 0; i < arrLength; i++)
        {
            // If the current element is greater than the current Max, update Max.
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;  // Return the maximum number found.
    }

    static int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = arr[0];  // Initialize Min with the first element of the array.

        // Loop through the array to find the smallest element.
        for (int i = 0; i < arrLength; i++)
        {
            // If the current element is less than the current minimum, update Min.
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;  // Return the minimum value found.
    }

    static int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;  // Initialize sum to zero.

        // Loop through each element of the array and add it to Sum.
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }

        return Sum;  // Return the calculated sum.
    }

    static float ArrayAverage(int arr[100], int arrLength)
    {
        // Compute the average by casting the sum to float to ensure floating-point division.
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        // Loop through each element up to arrLength and copy from source to destination.
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }


    enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

    static enPrimNotPrime CheckPrime(int Number)
    {
        // Compute M as roughly half of Number.
        // Note: Using round(Number / 2) here might not be the best approach
        // since for small numbers it may not be accurate; typically, we check until sqrt(Number).
        int M = round(Number / 2);

        // Loop from 2 to M to test for divisibility.
        for (int Counter = 2; Counter <= M; Counter++)
        {
            // If Number is divisible by any Counter, then it is not a prime.
            if (Number % Counter == 0)
                return enPrimNotPrime::NotPrime;  // Return NotPrime immediately.
        }

        // If no divisors were found, return Prime.
        return enPrimNotPrime::Prime;
    }

    static void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
    {
        int Counter = 0;  // Initialize a counter for the destination array index.

        // Loop through each element in the source array.
        for (int i = 0; i < arrLength; i++)
        {
            // If the current element is prime...
            if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
            {
                // Copy it to the destination array at the current counter index.
                arrDestination[Counter] = arrSource[i];
                Counter++;  // Increment the counter.
            }
        }

        // The code decrements Counter by 1 before assigning it to arr2Lenght.
        // Note: This is unusual as it reduces the count by one. It may be intended to adjust for 0-based indexing,
        // but typically the counter already reflects the number of primes found.
        arr2Lenght = --Counter;
    }

    static void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        // Loop through each index and add the corresponding elements from arr1 and arr2.
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];  // Store the sum in the arrSum array.
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }

    static void FillArrayWith1toN(int arr[100], int arrLength)
    {
        // Loop through each index and assign the value (index + 1) to that element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }

    static void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        // Loop through each element of the source array.
        // For each index i, copy the element at position (arrLength - 1 - i)
        // from the source array into the destination array at index i.
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[arrLength - 1 - i];
    }

    static void PrintStringArray(string arr[100], int arrLength)
    {
        cout << "\nArray elements:\n\n";
        // Loop through the array and print each element with its index.
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "] : ";
            cout << arr[i] << "\n";
        }
        cout << "\n"; // Extra newline for formatting.
    }

    static void FillArrayWithKeys(string arr[100], int arrLength)
    {
        // Loop through the array indices and generate a key for each element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey();
    }

    static short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        // Loop through each element in the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element equals the searched number.
            if (arr[i] == Number)
                return i; // Return the index immediately when the number is found.
        }

        // If the loop completes without finding the number, return -1.
        return -1;
    }

    static bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        // Use FindNumberPositionInArray and check if the result is not -1.
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }

    static void AddArrayElement(int Number, int arr[100], int& arrLength)
    {
        // Since it's a new element, increase the array length by 1.
        arrLength++;
        // Store the new element at the index corresponding to the updated length (using zero-based indexing).
        arr[arrLength - 1] = Number;
    }

    static int ReadNumber()
    {
        int Number;  // Variable to store the user's input.
        cout << "\nPlease enter a number? ";
        cin >> Number;  // Read the number from the user.
        return Number;  // Return the entered number.
    }

    static void InputUserNumbersInArray(int arr[100], int& arrLength)
    {
        bool AddMore = true;  // Boolean flag to control whether more numbers will be added.

        // Continue looping as long as the user wants to add more numbers.
        do
        {
            // Read a number from the user and add it to the array.
            AddArrayElement(ReadNumber(), arr, arrLength);

            // Ask the user if they want to add more numbers.
            // Input 0 for No, 1 for Yes.
            cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
            cin >> AddMore;  // Read user's decision (true if 1, false if 0).

        } while (AddMore);  // Continue looping if the user inputs true.
    }

    static void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        // Loop through each element of the source array.
        for (int i = 0; i < arrLength; i++)
            // Use AddArrayElement to copy the element to the destination array and update its length.
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
    }

    static void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        // Loop through each element of the source array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is odd.
            if (arrSource[i] % 2 != 0)
            {
                // If odd, add it to the destination array using the AddArrayElement function.
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }

    static void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        // Loop through each element of the source array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is prime using the CheckPrime function.
            if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
            {
                // If the number is prime, add it to the destination array.
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }

    static void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
    {
        // Loop through each element in the source array.
        for (int i = 0; i < SourceLength; i++)
        {
            // If the current element is not already in the destination array...
            if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
            {
                // ...then add it to the destination array.
                AddArrayElement(arrSource[i], arrDestination, DestinationLength);
            }
        }
    }

    static bool IsPalindromeArray(int arr[100], int Length)
    {
        // Loop through each element of the array.
        // We only need to check up to the middle of the array.
        for (int i = 0; i < Length; i++)
        {
            // Compare the element at position i with its corresponding element from the end.
            if (arr[i] != arr[Length - i - 1])
            {
                return false;  // If any pair doesn't match, the array is not a palindrome.
            }
        }

        // If all corresponding pairs match, the array is a palindrome.
        return true;
    }

    static int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;  // Initialize the odd number counter to 0.

        // Loop through each element in the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the element is odd (i.e., its remainder when divided by 2 is not 0).
            if (arr[i] % 2 != 0)
            {
                Counter++;  // Increment the counter if the element is odd.
            }
        }

        return Counter;  // Return the total count of odd numbers.
    }

    static int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;  // Initialize counter for even numbers to 0.

        // Loop through each element of the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is even.
            if (arr[i] % 2 == 0)
            {
                Counter++;  // Increment the counter if the element is even.
            }
        }

        return Counter;  // Return the total count of even numbers.
    }

    static int PositiveCount(int arr[100], int arrLength)
    {
        int Counter = 0;  // Initialize a counter for positive numbers.

        // Loop through each element of the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is positive (or zero).
            if (arr[i] >= 0)
            {
                Counter++;  // Increment the counter if the condition is met.
            }
        }

        return Counter;  // Return the total count of positive numbers.
    }

    static int NegativeCount(int arr[100], int arrLength)
    {
        int Counter = 0;  // Initialize a counter for negative numbers.

        // Loop through each element of the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is negative.
            if (arr[i] < 0)
            {
                Counter++;  // Increment the counter if the condition is met.
            }
        }

        return Counter;  // Return the total count of negative numbers.
    }

    static float MyABS(float Number)
    {
        // If the number is positive or zero, return it as is.
        if (Number > 0)
            return Number;
        else
            return Number * -1;  // If negative, multiply by -1 to make it positive.
    }

    static float GetFractionPart(float Number)
    {
        // Subtract the integer part of the number from the original number to get the fractional part.
        return Number - int(Number);
    }

    static int MyRound(float Number)
    {
        int IntPart;  // Variable to store the integer part of the number.
        IntPart = int(Number);  // Extract the integer part.

        // Compute the fractional part using the GetFractionPart function.
        float FractionsPart = GetFractionPart(Number);

        // If the absolute value of the fractional part is 0.5 or more, round the number accordingly.
        if (abs(FractionsPart) >= 0.5)
        {
            // If the number is positive, round up.
            if (Number > 0)
                return ++IntPart;
            // If the number is negative, round down.
            else
                return --IntPart;
        }
        else
        {
            // If the fractional part is less than 0.5, keep the integer part as is.
            return IntPart;
        }
    }

    static int MyFloor(float Number)
    {
        // If the number is positive or zero, return its integer part.
        if (Number > 0)
            return int(Number);
        else
            // If the number is negative and has a fractional part, subtract 1 to get the floor value.
            return int(Number) - 1;
    }

    static int MyCeil(float Number)
    {
        // If the number has a fractional part greater than zero, round up if positive.
        if (abs(GetFractionPart(Number)) > 0)
        {
            if (Number > 0)
                return int(Number) + 1;  // Round up for positive numbers.
            else
                return int(Number);  // Keep the integer part for negative numbers.
        }
        else
            return Number;  // If the number is already an integer, return it as is.
    }

    static float MySqrt(float Number)
    {
        return pow(Number, 0.5);  // Compute the square root using the power function.
    }

};


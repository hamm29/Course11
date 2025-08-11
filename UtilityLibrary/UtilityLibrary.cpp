
#include <iostream>
#include "clsUtil.h"

using namespace std;
//using namespace clsUtilityLib;

int main()
{
    int arr[10] = { 32,32,2,1,5,6,32,7,2,2 };
    clsUtil::Srand();
    cout << clsUtil::GenerateKey();

    cout << endl;
    cout << clsUtil::TimesRepeated(32, arr, 10) << "\n";
    clsUtil::PrintArray(arr, 10);

    system("pause>0");

}

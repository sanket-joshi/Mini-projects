//LargestProductConsecutiveNumbers.cpp
//Sanket Joshi
//
//This program will take in a large integer from the user and a second integer from the user which represents the number of possible consectutive numbers to crate the largest possible product from the digits of the first number
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    //Declare Variables
    string StringNum;
    int num;
    int digit;
    int ProductConsecNums = 1;
    int LargestProduct = 0;
    vector <int> DigitNums;

    //User enters the number in as a string so it can handle a large number of digits
    cout << "Enter a positive number" << endl;
    getline(cin,StringNum);
    //If the user enters a non positive number
    while (StringNum[0] == '-')
    {
        cout << "not positive number" << endl;
        getline(cin,StringNum);
    }
    //User enters the n value, the number of consecutive numbers to form a product
    cout << "Enter the number of consecutive numbers to find the product of" << endl;
    cin >> num;
    //If the user enters a non positive number
    while (num <= 0)
    {
        cout << "Enter a positive number" << endl;
        cin >> num;
    }

    //convert the StringNum into an integer
    for (int  i= 0; i < (int)StringNum.length(); i++)//digits are taken from the string and turned into individual integers
    {
        stringstream ss;//string stream declared
        ss << StringNum[i];//take each element of the string ie the characters
        ss >> digit;//and convert them into integers
        DigitNums.push_back(digit);//put integers from string into a vector so they can be compared to see if they are consecutive numbers
        //cout << digit << endl;
    }

    for (int i = 0; i < (int)StringNum.length()-num +1;i++)
    {
        for (int j = 0; j < num; j++)
        {
            ProductConsecNums *= DigitNums [j+i];//the product of the consecutive numbers is equal to sum of the digits in vector position of the sum of i and j
        }
        if (ProductConsecNums > LargestProduct)
            LargestProduct = ProductConsecNums;//when the product of the consecutive numbers is greater then the largest product, then set the largest product euqal to the product of the consecutive numbers
        ProductConsecNums = 1;
    }

    if (LargestProduct == 0)
        cout << "Error" << endl;
    else
        cout << "Largest product of consecutive numbers is " << LargestProduct << endl;

    return 0;
}

/*TEST CASE
Enter a positive number
12345
Enter the number of consecutive numbers to find the product of
3
Largest product of consecutive numbers is 60

Process returned 0 (0x0)   execution time : 10.030 s
Press any key to continue.

TEST CASE 2
Enter a positive number
56
Enter the number of consecutive numbers to find the product of
3
Error

Process returned 0 (0x0)   execution time : 3.297 s
Press any key to continue.

TEST CASE 3
Enter a positive number
-4324325342
not positive number
435345432324
Enter the number of consecutive numbers to find the product o
3
Largest product of consecutive numbers is 80

Process returned 0 (0x0)   execution time : 9.357 s
Press any key to continue.

*/

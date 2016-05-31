//RecursiveFactorial.cpp
//Sanket Joshi
//
//This program will use recursion to create a factorial function using input, n, from the user

#include <iostream>

using namespace std;

int Factorial (int n);

int main()
{
    //Declare Variables
    int num;
    int PrintFactorial;

    //User prompt and input
    cout << "Enter a positive number please:" << endl;
    cin >> num;

    while (num < 0)
    {
        cout << "Enter a positive number" << endl;
        cin >> num;
    }
    cout << endl;//formatting

    PrintFactorial = Factorial(num);//Call the function to display the factorial value based on user input

    //Display output
    cout << "The value of " << num  << " factorial is " << PrintFactorial << endl;

    return 0;
}

int Factorial(int n)//n represents the term number
{
    int value;

    if (n == 1)
        return 1;//Recursion will continue until it reaches 1, which is the first term in the factorial list

    value = Factorial(n-1)*n;//Multiplies the current term by the previous term and will continue until it reaches the first term, which has a value of 1
    return value;//return the value of the nuxt, most updated term
}

/* TEST CASE

Enter a positive number please:
6

The value of 6 factorial is: 720

Process returned 0 (0x0)   execution time : 1.642 s
Press any key to continue.

TEST CASE 2

Enter a positive number please:
-434
Enter a positive number
-4234325
Enter a positive number
13

The value of 13 factorial is 1932053504

Process returned 0 (0x0)   execution time : 8.135 s
Press any key to continue.

TEST CASE 3

Enter a positive number please:
-343
Enter a positive number
9

The value of 9 factorial is 362880

Process returned 0 (0x0)   execution time : 10.201 s
Press any key to continue.
*/


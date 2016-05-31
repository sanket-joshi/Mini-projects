//RecursizeComma
//Sanket Joshi
//
//This program will use recursion to print commas between every third digit of a user given number
#include <iostream>

using namespace std;

//Initialize Prototype Function
void WriteCommas (int num);
void Write3Digits (int num);

int main()
{
    //Declare Varibales
    int num;

    //User prompt and input
    cout << "Please enter a number greater than 0:" << endl;
    cin >> num;

    //Incase user enters inappropriate input
    while (num <= 0)
    {
        cout << "Number must be greater than 0. Try again:" << endl;
        cin >> num;
    }
    cout << endl;//formatting

    WriteCommas(num);//call the function to print commas between every third digit of a number
    return 0;
}

void WriteCommas(int num)
{
    if (num < 1000)
        cout << num;//print the number without a comma if it is less then 1000
    else
    {
        WriteCommas(num/1000);//every 3rd digit needs a comma after it
        cout << ",";
        Write3Digits (num%1000);//prints the remaining digits in the number

    }
}

void Write3Digits(int num)
{
    if (num<100)//if the remainder from WriteCommas is less then 100, then add a 0 to it
        cout<<"0";
    if (num<10)//if the remainder from WriteCommas is less then 10, then add a 0 to it
        cout<<"0";
    WriteCommas(num);//The number is sent to the WriteCommas Function and will be printed properly
}

/*TEST CASE

Please enter a number greater than 0:
70000000

70,000,000
Process returned 0 (0x0)   execution time : 5.961 s
Press any key to continue.

TEST CASE 2

Please enter a number greater than 0:
-545
Number must be greater than 0. Try again:
-57
Number must be greater than 0. Try again:
-5654
Number must be greater than 0. Try again:
0
Number must be greater than 0. Try again:
534654654

534,654,654
Process returned 0 (0x0)   execution time : 10.420 s
Press any key to continue.

TEST CASE 3

Please enter a number greater than 0:
849348593

849,348,593
Process returned 0 (0x0)   execution time : 3.823 s
Press any key to continue.

*/

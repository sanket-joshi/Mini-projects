//NumSeconds.cpp
//Sanket Joshi
//
//this program will take the number of seconds since midnight and calculates the hours, minutes and seconds since midnight

#include <iostream>

using namespace std;

void splitTime(long totalSec, int *hour, int *minute, int *sec);//prototype function to calculate the hours,minutes and seconds since midnight

int main()
{
    //Declare Variables
    long seconds;
    int hours;
    int minutes;
    int finalsec;

    //User prompt and input
    cout << "Please enter the number of seconds since midnight" << endl;
    cin >> seconds;
    //Incase user enters invalid input
    while (seconds < 0)
    {
        cout << "Enter a positive number of seconds since midnight" << endl;
        cin >> seconds;
    }
    cout << endl;//formatting



    splitTime (seconds, &hours, &minutes, &finalsec);//points to the adress of int variables in the main

    cout << seconds << " seconds is " << hours << " hours " << minutes << " minutes " << finalsec << " seconds, since midnight " << endl;

    return 0;
}

void splitTime(long totalSec, int *hour, int *minute, int *sec)
{
    int Remseconds;//the remaining seconds

    //Calculations
    *hour = totalSec / 3600;//to find the hours, divide the total number of seconds by 3600
    Remseconds = totalSec % 3600;//to find the remaining seconds after hours was calulated, find the remainder of total seconds divided by 3600
    *minute = Remseconds / 60;//to find the minutes take the remaining seconda fter hours calculation and divide it by 60
    *sec = Remseconds % 60;//to fidn the final number of seconds, find the remainder of the remaining seconds divided by 60
}

/*TEST CASE

Please enter the number of seconds since midnight
7313

7313 seconds is 2 hours 1 minutes 53 seconds, since midnight

Process returned 0 (0x0)   execution time : 27.176 s
Press any key to continue.

TEST CASE 2

Please enter the number of seconds since midnight
-5
Enter a positive number of seconds since midnight
-43
Enter a positive number of seconds since midnight
43534

43534 seconds is 12 hours 5 minutes 34 seconds, since midnight

Process returned 0 (0x0)   execution time : 19.347 s
Press any key to continue.

TEST CASE 3

Please enter the number of seconds since midnight
-56
Enter a positive number of seconds since midnight
11456

11456 seconds is 3 hours 10 minutes 56 seconds, since midnight

Process returned 0 (0x0)   execution time : 10.840 s
Press any key to continue.

*/

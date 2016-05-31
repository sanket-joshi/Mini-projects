//NumberPartition.cpp
//Sanket Joshi
//
//This program will take take two numbers, r and n, where r is the number of way to write n as a sum of other numbers less then n, using a partition
#include <iostream>


using namespace std;



void partition(int r, int n, int currIndex, int currToAdd, int* sol);//prototype for partition function


int main()
{
    //Declare Variables
    int n;
    int r;

    //User prompt and input for the number to partition
    cout << "Enter a positive number to parition (n)" << endl;
    cin >> n;
    cout << endl;
    //In case user enters invalid input
    while (n <= 0)
    {
        cout << "Error! Enter a positive number" << endl;
        cin >> n;
        cout << endl;
    }

    //User prompt and input for the partition number
    cout << "Enter a positive parition number (r)" << endl;
    cin >> r;
    cout << endl;

    //the largest possible partition for a number is itself and so r cannot be greater then  n, and also checks if user entered invalid input
    while ((r > n) || (r <= 0))
    {
        if (r > n)//output to user if partiton number is greater then n
        {
            cout << "The partiton number must be less then the number being partitioned!" << endl;
            cin >> r;
            cout << endl;
        }
        if ( r <= 0)//output to user if partition number is not positive
        {
            cout << "Error! Enter a positive partition number!" << endl;
            cin >> r;
            cout << endl;
        }

    }

    int *sol = new int[r];//makes a new array of the size r, the partition number because it represents the possible combinations of writing n, its a pointer so everytime the function calls itself and holds the memory location of previous elements
    partition(r, n, r-1, n-1, sol);//calls the partition function, r-1 is the index which is where a new number is placed and decreases until it reaches 0, n-1 is the first number being added or first guess
    return 0;
}


void partition(int r, int n, int currIndex, int currToAdd, int* sol)
{
    if (currIndex < 0)//if the array is filled up from n to 0
    {
        int sum = 0;
        for (int i = 0; i < r; i++)
        {
            sum += sol[i];//checking the array to see if elements add up to the sum
        }
        if (sum == n)//if the sum equals the user entered number
        {
            for (int i = 0; i < r; i++)
            {
                cout << sol[i] << " ";//display the numbers adding up to n with the parameters
            }
            cout << endl;
        }
    }
    else//if the array isn't complete/ the array is not filled with numbers that add up to n
    {

        for (int i = currToAdd; i >= 1; i--)//coutning down from the current number to being added up to 1 and decreasing each time
        {
            sol[currIndex] = i;//i is now the current guess for the index to see if adds to n
            partition(r,n,currIndex-1,i,sol);//calling itself to guess what the next index number is to add to n
        }
    }
}

/* TEST CASE

Enter a positive number to parition (n)
7

Enter a positive parition number (r)
3

1 1 5
1 2 4
1 3 3
2 2 3

Process returned 0 (0x0)   execution time : 3.392 s
Press any key to continue.

TEST CASE 2

Enter a positive number to parition (n)
-4

Error! Enter a positive number
14

Enter a positive parition number (r)
-5

Error! Enter a positive partition number!
34

The partiton number must be less then the number being partitioned!
-8

Error! Enter a positive partition number!
4

1 1 1 11
1 1 2 10
1 1 3 9
1 2 2 9
1 1 4 8
1 2 3 8
2 2 2 8
1 1 5 7
1 2 4 7
1 3 3 7
2 2 3 7
1 1 6 6
1 2 5 6
1 3 4 6
2 2 4 6
2 3 3 6
1 3 5 5
2 2 5 5
1 4 4 5
2 3 4 5
3 3 3 5
2 4 4 4
3 3 4 4

Process returned 0 (0x0)   execution time : 21.776 s
Press any key to continue.

TEST CASE 3

Enter a positive number to parition (n)
18

Enter a positive parition number (r)
3567

The partiton number must be less then the number being partitioned!
-45

Error! Enter a positive partition number!
345

The partiton number must be less then the number being partitioned!
7

1 1 1 1 1 1 12
1 1 1 1 1 2 11
1 1 1 1 1 3 10
1 1 1 1 2 2 10
1 1 1 1 1 4 9
1 1 1 1 2 3 9
1 1 1 2 2 2 9
1 1 1 1 1 5 8
1 1 1 1 2 4 8
1 1 1 1 3 3 8
1 1 1 2 2 3 8
1 1 2 2 2 2 8
1 1 1 1 1 6 7
1 1 1 1 2 5 7
1 1 1 1 3 4 7
1 1 1 2 2 4 7
1 1 1 2 3 3 7
1 1 2 2 2 3 7
1 2 2 2 2 2 7
1 1 1 1 2 6 6
1 1 1 1 3 5 6
1 1 1 2 2 5 6
1 1 1 1 4 4 6
1 1 1 2 3 4 6
1 1 2 2 2 4 6
1 1 1 3 3 3 6
1 1 2 2 3 3 6
1 2 2 2 2 3 6
2 2 2 2 2 2 6
1 1 1 1 4 5 5
1 1 1 2 3 5 5
1 1 2 2 2 5 5
1 1 1 2 4 4 5
1 1 1 3 3 4 5
1 1 2 2 3 4 5
1 2 2 2 2 4 5
1 1 2 3 3 3 5
1 2 2 2 3 3 5
2 2 2 2 2 3 5
1 1 1 3 4 4 4
1 1 2 2 4 4 4
1 1 2 3 3 4 4
1 2 2 2 3 4 4
2 2 2 2 2 4 4
1 1 3 3 3 3 4
1 2 2 3 3 3 4
2 2 2 2 3 3 4
1 2 3 3 3 3 3
2 2 2 3 3 3 3

Process returned 0 (0x0)   execution time : 50.071 s
Press any key to continue.

TEST CASE 4

Enter a positive number to parition (n)
-67

Error! Enter a positive number
13

Enter a positive parition number (r)
67

The partiton number must be less then the number being partitioned!
-654

Error! Enter a positive partition number!
56

The partiton number must be less then the number being partitioned!
8

1 1 1 1 1 1 1 6
1 1 1 1 1 1 2 5
1 1 1 1 1 1 3 4
1 1 1 1 1 2 2 4
1 1 1 1 1 2 3 3
1 1 1 1 2 2 2 3
1 1 1 2 2 2 2 2

Process returned 0 (0x0)   execution time : 21.215 s
Press any key to continue.

*/

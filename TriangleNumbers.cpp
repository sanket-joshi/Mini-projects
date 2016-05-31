//TriangleNumbers.cpp
//Sanket Joshi
//
//This program will take a positive integer from the user and display the first triangular numbers up to the user determined number

#include <iostream>

using namespace std;

int main()
{
    //Initialize variables
    int num;
    int trinum;

    //Collect information
    cout << "Please enter a number greater then zero" << endl;
    cin >> num;
    cout << endl;


    //Make sure number is positive
    while (num <= 0)
    {
        cout << "Enter a number greater then zero" << endl;
        cin >> num;
    }

    //Display output
    cout << "The first triangular numbers up to " << num << " are: " << endl;

    //Calculate the triangular numbers up to the user determined number
    for (int i = 1; i <= num; i++)
    {
        trinum = (i*(i+1))/2;//arithmetic series formula
        cout << trinum << endl;//display the triangular numbers
    }


    return 0;
}

/* TEST CASE

Please enter a number greater then zero
12

The first triangular numbers up to 12 are:
1
3
6
10
15
21
28
36
45
55
66
78

Process returned 0 (0x0)   execution time : 5.117 s
Press any key to continue.

TEST CASE 2

Enter a number greater then zero
-454
Enter a number greater then zero
0
Enter a number greater then zero
14
The first triangular numbers up to 14 are:
1
3
6
10
15
21
28
36
45
55
66
78
91
105

Process returned 0 (0x0)   execution time : 18.604 s
Press any key to continue.

TEST CASE 3

Please enter a number greater then zero
-9134

Enter a number greater then zero
31
The first triangular numbers up to 31 are:
1
3
6
10
15
21
28
36
45
55
66
78
91
105
120
136
153
171
190
210
231
253
276
300
325
351
378
406
435
465
496

Process returned 0 (0x0)   execution time : 16.491 s
Press any key to continue.


*/

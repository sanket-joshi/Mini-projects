//ReverseLinkedList.cpp
//Sanket Joshi
//
//This program will output the contents of a linked list in reverse order

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

ostream & operator << (ostream &stream, node *list)
{
    while (list != NULL)//while the list is not empty
    {
        stream << list -> data << " ";
        list = list -> next;//looks at the next node
    }
    return stream;
}

//takes current node and returns the node appended to current
node *appendList (node *current, int newData)
{
    node *newNode;
    //create a new node
    newNode = new node;
    newNode -> data = newData;//new node has the value of count*count
    newNode -> next = NULL;//already at end of list, next node is NULL

    current -> next = newNode;//going to point to the new node made

    return newNode;
}

void destroyList (node *begin)
{
    node *current;
    node *temp;

    if (begin == NULL)//if theres nothing in the list
        return;

    current = begin -> next;

    while (current != NULL)//current exists
    {
        begin -> next = current -> next;//begin next is equal current next
        temp = current -> next;
        delete current;
        current = temp;
    }

    delete begin;
}


//Function for printing out list in reverse order
void revlist(node *begin)
{
   if (begin == NULL)//function ends if there is nothing else left to read
       return;
   revlist (begin -> next);//via recursion, the function goes to the end of the list
   cout << begin -> data << " ";//and prints the data on its way back to the beggining
}

int main()
{
    //Declare nodes
    node *current;
    node *begin;

    //Declare variables
    int count;
    int maxLoop = 10;

    //allocate the starting node
    current = new node;
    current -> data = 1;//begin points to this and current points to this
    current -> next = NULL;//points to nothing
    begin = current;

    for (int count = 2; count < maxLoop; count++)
        current = appendList(current, count*count);//fills the contents of the list with perfect squares

    //Print Forwards List
    cout << "The list in order is " << begin << endl;
    cout << endl;

    //Print Backwards List
    cout << "After initializing, the list in reverse order is ";
    revlist(begin);//calls the function and prints the data in reverse order
    cout << endl;

    destroyList (begin);//destroy the list

    return 0;
}

/* TEST CASE
The list in order is 1 4 9 16 25 36 49 64 81

After initializing, the list in reverse order is 81 64 49 36 25 16 9 4 1

Process returned 0 (0x0)   execution time : 0.046 s
Press any key to continue.
*/

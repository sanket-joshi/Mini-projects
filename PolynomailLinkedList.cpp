//DoublyLinkedList.cpp
//Sanket Joshi
//
//This program will apply a doubly linked list with the specific functions create, destroy, erase, insert, printForward and printBackward functions
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;//points to the next node
    node *prev;//points to the previous node
};

ostream & operator << (ostream &stream, node *list)
{
    while (list != NULL)//while the list is not empty
    {
        stream << list -> data << " ";//add a space between each element in the list
        list = list -> next;
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
    newNode -> prev = current;

    current -> next = newNode;//going to point to the new node made

    return newNode;
}

//Function to insert a number into the list
node *InsertNumList(node *current, int UserNum, int UserPosition)
{
    node *temp;
    node *ret = current;//ret is the return value
    temp = current;
    node *newnode;
    newnode = new node;
    newnode -> data = UserNum;
    if (UserPosition == 0)
    {
        temp -> prev = newnode;//linking the prev to newnode
        newnode -> next =  temp;//newnode is linked to the next node
        newnode -> prev = NULL;//the prev is still pointing to nothing since it is at the beginning of the list
        ret = newnode;
        return ret;
    }

    for (int i = 0; i < UserPosition - 1; i++)
    {
        temp = temp -> next;//temp is made to equal the node before the nth node in the list
    }
    if (temp -> next == NULL)//if the user inserts a number at the end of the list, the next pointer is pointing to nothing and must be linked backed to the previous node
    {
        temp -> next = newnode;//linking the next (which is poinint to nothing) to newnode
        newnode -> prev = temp;//linking the newnode back to the previous node
        newnode -> next = NULL;//the next is still pointing to nothing since it is at the front of the list
    }
    else//if the user doesn't insert at the beginning of the list or at the end of the list then continue to insert the number into the list
    {
        temp -> next -> prev = newnode;//the new node is given a previous and next pointer as element was entered in the middle of list
        newnode -> prev = temp;//the new node is then inserted after temp
        newnode -> next = temp -> next;//temp is the newnode linking to the next
        temp -> next = newnode;//temp next is now the new node
    }


    return ret;
}

//Function to erase a number from the list
node* EraseNumList(node *current, int UserPosition)
{
    node *ret = current;//ret is a return value
    node *temp;
    temp = current;

    for (int i=0; i < UserPosition - 1; i++)
        temp = temp -> next;//temp keeps going to the next node until it is the nth node in the list

    if (temp -> next == NULL)//if the user erases a number at the end of the list, the next pointer is pointing to nothing and must be linked backed to the previous node
    {
        temp -> prev -> next = NULL;//the element before ,prev, the one being erased is now pointing to nothing
    }
    else if (temp -> prev == NULL)//if the user erases a number at the beginning of the list, the previous pointer is pointing to nothing and must be linked to the next node
    {
        temp -> next -> prev = NULL;//the element after, next, the one beging erased is now pointing to nothing (NULL)
        ret = temp -> next;
    }
    else//if the user doesn't insert at the beginning of the list or at the end of the list then continue to insert the number into the list
    {
        node *tempPrev = temp -> prev;//nodes for the previous position
        node *tempNext = temp -> next;//node for the next position
        tempNext -> prev = tempPrev;//when the user erases a number from the middle of the list, the element on either side of it must be linked together, this line links with the element previous to one being erased
        tempPrev -> next = tempNext;//links with the element infront of the one being erased
    }


    delete temp;//delete the element from the list
    return ret;
}

//Function to find the length of the list
int listLen(node *n)
{
    int len = 0;
    node* list = n;
    while (list != NULL)
    {
        len++;
        list = list -> next;
    }
    return len;
}

//Function to destroy the list
void destroyList (node *begin)
{
    node *current;
    node *temp;

    if (begin == NULL)
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
void printBackward(node *begin)
{
    if (begin==NULL)//function ends if there is nothing else left to read
        return;
    printBackward (begin->next);//via recursion, the function goes to the end of the list
    cout<<begin->data<<" ";//and prints the data on its way back to the beggining
}

//Function for printing list forwards
void printForward (node *begin)
{
    if (begin != NULL)
    {
        cout << begin ->data << " ";
        printForward(begin->next);
    }
}

//Function to print the command list
void helpCMD()
{
    cout << "Select a command:" << endl;
    cout << "f - prints the list in forward" << endl;
    cout << "b - prints the list in backward" << endl;
    cout << "i - insert an element into the list" << endl;
    cout << "e - delete an element from the list" << endl;
    cout << "l - length of the list" << endl;
    cout << "y - Popback" << endl;
    cout << "x - Dequeue" << endl;
    cout << "z - Enqueue" << endl;
    cout << "h - shows this table again" << endl;
    cout << "q - quit the program" << endl;
}

//Function to handle input for insertion into the list
node* insertCMD(node *begin)
{
    int num, PositionInsert;
    //Inserting number into the list based on user input
    cout << "Please enter a number to insert into the list:" << endl;
    cin >> num;
    cout << endl;
    cout << "Please enter the position in the list to insert:" << num  << " into the list : " << endl;//the position in the list starts at 0 for the first element
    cin >> PositionInsert;
    cout << endl;
    cout << "The number " << num << " was inserted into the list at position " << PositionInsert << " : " << endl;
    begin = InsertNumList (begin,num,PositionInsert);
    cout << begin << endl;//print out the new list with the used inserted number
    cout << endl;
    return begin;
}

//Function to handle input for erasing an element from the list
node* eraseCMD(node *begin)
{
    int PositionErase;
    //Erasing number from the list based on what position the user wants to erase from the list
    cout << "Please enter the position of the element in the list you would like to erase:" << endl;//the position in the list starts from 0
    cin >> PositionErase;
    cout << endl;
    cout << "The element at position " << PositionErase << " was erased from the list:" << endl;
    begin = EraseNumList (begin, PositionErase);
    cout << begin << endl;//prints the new list with the element from the user determined position being erased from the list
    cout << endl;
    return begin;
}
int main()
{
    //Declare the nodes
    node *current;
    node *begin;

    //allocate the starting node
    current = new node;
    current -> data = 1;//begin points to this and current points to this
    current -> next = NULL;//points to nothing for next
    current -> prev = NULL;//points to nothing for prev
    begin = current;

    //Declare Variables
    int maxLoop = 10;


    for (int count = 2; count < maxLoop; count++)
        current = appendList(current, count*count);//populate the list with perfect squares upto, not including, 10

    helpCMD();//call the command list

    char cmd;//variable to take input from user so user can select option from command list

    while(true)
    {
        cout << endl;
        cout << "Please enter a command." << endl;
        cin >> cmd;
        cout << endl;
        if (cmd == 'q')//quit program
        {
            break;
        }
        else if (cmd == 'i')//insert into list
        {
            begin = insertCMD(begin);
        }
        else if (cmd == 'f')//print list forwards
        {
            cout << "List Forwards is: ";
            printForward(begin);
            cout<<endl;
        }
        else if (cmd == 'b')//print list backwards
        {
            cout << "List Backwards is: ";
            printBackward(begin);
            cout<<endl;
        }
        else if (cmd == 'e')//erase an element from the list
        {
            begin = eraseCMD(begin);
        }
        else if (cmd == 'l')//ptints the length of the list
        {
            cout << "The lenght of the list is "  << listLen(begin)<< endl;
        }
        else if (cmd == 'h')//prints the command list
        {
            helpCMD();
        }
        else if (cmd == 'y')//stack implementation
        {
            cout << "The element was popped back" << endl;
            begin = EraseNumList(begin, listLen(begin));
            cout << begin << endl;
        }
        else if (cmd == 'x')//queue front
        {
            cout << "The element was popped back" << endl;
            begin = EraseNumList(begin, 0);
            cout << begin << endl;
        }
        else if (cmd == 'z')//queue back
        {
            cout << "The element 10 was pushed back/enqueue" << endl;
            begin = InsertNumList(begin, 10 , listLen(begin));
            cout << begin << endl;
        }
        else//if input doesn't match any command from list
        {
            cout << "Command not found. Press 'h' for more help" << endl;
        }

    }

    //Destroy the list
    destroyList (begin);

    return 0;
}

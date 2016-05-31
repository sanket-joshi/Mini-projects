//ParentNode.cpp
//Sanket Joshi
//
//This program uses the concept of a parent node to add and erase elemnts from a binary search tree, print the tree and insert elemnts into the tree
//Only code that was added to the code given in class will be commented
#include <iostream>
#include <cstdio>

using namespace std;


struct node
{
    int data;
    node *left;
    node *right;
    node *parent;//parent node
};

node * insert (int data, node **tree);
void erase (int key, node **tree);
void destroy (node *tree);
node *search (int key, node *tree);
void structure (node *root, int level );


int main()
{
    node *root = NULL;
    node *curr = NULL;

    int value;

    //User prompt
    while (true)
    {
        cout << "Enter an integer, zero to quit" << endl;
        cin >> value;

        if (value == 0)
            break;

        curr = insert (value, &root);
        structure(root,0);
    }
    //Erasing a value from the tree
    while (true)
    {
        cout << "Erase value from tree:" << endl;
        cin >> value;

        if (value == 0)
            break;

        erase (value, &root);
        structure(root,0);
    }


    destroy(root);

    return 0;
}


node *createNode (int data)
{
    node *newNode = NULL;
    newNode = new node;
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> parent = NULL;//Newnodes parent points to nothing
    return newNode;
}

void destroy(node *tree)
{
    if (tree != NULL)
    {
        if (tree -> left != NULL)
            destroy(tree -> left);
        if (tree -> right != NULL)
            destroy(tree -> right);
        delete tree;
    }
}

node *insert (int data, node **tree)
{
    node *newNode = NULL;

    if (*tree == NULL)
    {
        newNode = createNode(data);
        *tree = newNode;
    }
    else if (data < (*tree) -> data)
    {
        if ((*tree) -> left == NULL)
        {
            newNode = createNode(data);
            (*tree) -> left = newNode;
            newNode -> parent = (*tree);//newnodes parent is now equal to the position of the tree
        }
        else
            newNode = insert (data, &((*tree) -> left));
    }
    else
    {
        if ((*tree) -> right == NULL)
        {
            newNode = createNode(data);
            (*tree) -> right = newNode;
            newNode -> parent = (*tree);//newnodes parent is now equal to the position of the tree
        }
        else
            newNode = insert (data, &((*tree) -> right));
    }



    return newNode;
}

void insertNode (node *newNode, node **tree)
{
    if (newNode == NULL) return;
    int data = newNode->data;
    if (data < (*tree) -> data)
    {
        if ((*tree) -> left == NULL)
        {
            (*tree) -> left = newNode;
            newNode -> parent = (*tree);//newnodes parent is now equal to the position of the tree
        }
        else
            insertNode (newNode, &((*tree) -> left));
    }
    else
    {
        if ((*tree) -> right == NULL)
        {
            (*tree) -> right = newNode;
            newNode -> parent = (*tree);//newnodes parent is now equal to the position of the tree
        }
        else
            insertNode (newNode, &((*tree) -> right));
    }

    return;
}

//Function to delete nodes from tree
void erase (int key, node **tree)
{
    node* toDelete = search(key, *tree);

    while (toDelete == NULL)
    {
        cout << "That was not in the tree. Can't delete." << endl;//if the user enters invalid input
        return;
    }

    node* right = toDelete -> right;//the right node is equal to the right branch of the node to be deleted
    node* left = toDelete -> left;//the left node is equal to the left branch of the node to be deleted

    if (right != NULL)//if the right node is pointing to something
    {
        toDelete -> data = right -> data;//the data of the node to be deleted is equal to the data of the right node
        toDelete -> right = right -> right;//the right branch of the node to be deleted is now equal to the right branch of the right node
        toDelete -> left = right -> left;//the left branch of the node to be deleted is now equal ro the left branch of the right node

        delete right;//delete the right node
        insertNode(left, &toDelete);
    }
    else if(left != NULL)//if the left node is pointing to something
    {
        toDelete -> data = left -> data;//the data of the node to be deleted is equal to the data of the left node
        toDelete -> right = left -> right;//the right branch of the node to be deleted is now equal to the right branch of the left node
        toDelete -> left = left -> left;//the left branch of the node to be deleted is now equal ro the left branch of the left node
        delete left;
    }
    else
    {
        node *parent = toDelete->parent;//the parent node is now equal to the parent of the node being deleted
        if (parent -> left == toDelete)
            parent -> left = NULL;//if the left branch of the parent is euqal todelte
        else if (parent -> right == toDelete)//or if the right breanch of parent is equal to the node being deleted
            parent -> right = NULL;//then the right branch of the parent is pointing to nothing, equal to null
        delete toDelete;
    }
}

node *search (int key, node *tree)
{
    if (tree == NULL || tree -> data == key)
        return tree;
    if (key < tree -> data)
        return search (key, tree -> left);
    else
        return search (key, tree -> right);
}

void padding ( char ch, int n )
{
    int i;
    for ( i = 0; i < n; i++ )
        putchar ( ch );
}
void structure (node *root, int level )
{
    int i;
    if ( root == NULL )
    {
        padding ( '\t', level );
        puts ( "~" );
    }
    else
    {
        structure ( root->right, level + 1 );
        padding ( '\t', level );
        printf ( "%d\n", root->data );
        structure ( root->left, level + 1 );
    }
}

/*TEST CASE
Enter an integer, zero to quit
4
        ~
4
        ~
Enter an integer, zero to quit
7
                ~
        7
                ~
4
        ~
Enter an integer, zero to quit
9
                        ~
                9
                        ~
        7
                ~
4
        ~
Enter an integer, zero to quit
4
                        ~
                9
                        ~
        7
                        ~
                4
                        ~
4
        ~
Enter an integer, zero to quit
2
                        ~
                9
                        ~
        7
                        ~
                4
                        ~
4
                ~
        2
                ~
Enter an integer, zero to quit
1
                        ~
                9
                        ~
        7
                        ~
                4
                        ~
4
                ~
        2
                        ~
                1
                        ~
Enter an integer, zero to quit
0
Erase value from tree:
7
                ~
        9
                        ~
                4
                        ~
4
                ~
        2
                        ~
                1
                        ~
Erase value from tree:
4
        ~
9
                ~
        4
                        ~
                2
                                ~
                        1
                                ~
Erase value from tree:
9
        ~
4
                ~
        2
                        ~
                1
                        ~
Erase value from tree:
1
        ~
4
                ~
        2
                ~
Erase value from tree:
0

Process returned 0 (0x0)   execution time : 24.598 s
Press any key to continue.


TEST CASE 2

Enter an integer, zero to quit
9
        ~
9
        ~
Enter an integer, zero to quit
1
        ~
9
                ~
        1
                ~
Enter an integer, zero to quit
3
        ~
9
                        ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
4
        ~
9
                                ~
                        4
                                ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
11
                ~
        11
                ~
9
                                ~
                        4
                                ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
14
                        ~
                14
                        ~
        11
                ~
9
                                ~
                        4
                                ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
78
                                ~
                        78
                                ~
                14
                        ~
        11
                ~
9
                                ~
                        4
                                ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
3
                                ~
                        78
                                ~
                14
                        ~
        11
                ~
9
                                ~
                        4
                                        ~
                                3
                                        ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
0
Erase value from tree:
9
                        ~
                78
                        ~
        14
                ~
11
                                ~
                        4
                                        ~
                                3
                                        ~
                3
                        ~
        1
                ~
Erase value from tree:
11
                ~
        78
                ~
14
                                ~
                        4
                                        ~
                                3
                                        ~
                3
                        ~
        1
                ~
Erase value from tree:
4
                ~
        78
                ~
14
                                ~
                        3
                                ~
                3
                        ~
        1
                ~
Erase value from tree:
1
                ~
        78
                ~
14
                        ~
                3
                        ~
        3
                ~
Erase value from tree:
0

Process returned 0 (0x0)   execution time : 31.540 s
Press any key to continue.

*/

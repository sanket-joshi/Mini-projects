//MirrorTree.cpp
//Sanket Joshi
//
//This program will make a mirror of a binary tree
//Only code that was added to the one given from class is commented as this program uses code given in class
#include <iostream>
#include <cstdio>
using namespace std;


struct node
{
    int data;
    node * left;
    node *right;
};

node * insert (int data, node **tree);
void destroy (node *tree);
void MirrorTree (node *root);
void structure (node *root, int level );


int main()
{
    //Declare nodes
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


    MirrorTree(root);//call the mirror function
    structure(root, 0);



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
        }
        else
            newNode = insert (data, &((*tree) -> right));
    }

    return newNode;
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
  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  }
  else {
    structure ( root->right, level + 1 );
    padding ( '\t', level );
    printf ( "%d\n", root->data );
    structure ( root->left, level + 1 );
  }
}

void MirrorTree (node *root)
{
     if (root == NULL)//if there is no root, then there is no mirror
        return;
    else
    {
        node *tmp = root->left;//the temporary node is equal to the left branch of the root
        root->left = root->right;//the left branch of the root is now the right branch, mirroring the original tree
        root->right = tmp;//the right branch of the root is now the temporary node
        MirrorTree(root->left);//recursion used to mirror the original tree
        MirrorTree(root->right);
    }
}

/*TEST CASE
Enter an integer, zero to quit
4
        ~
4
        ~
Enter an integer, zero to quit
5
                ~
        5
                ~
4
        ~
Enter an integer, zero to quit
6
                        ~
                6
                        ~
        5
                ~
4
        ~
Enter an integer, zero to quit
3
                        ~
                6
                        ~
        5
                ~
4
                ~
        3
                ~
Enter an integer, zero to quit
24
                                ~
                        24
                                ~
                6
                        ~
        5
                ~
4
                ~
        3
                ~
Enter an integer, zero to quit
5
                                ~
                        24
                                ~
                6
                                ~
                        5
                                ~
        5
                ~
4
                ~
        3
                ~
Enter an integer, zero to quit
-9
                                ~
                        24
                                ~
                6
                                ~
                        5
                                ~
        5
                ~
4
                ~
        3
                        ~
                -9
                        ~
Enter an integer, zero to quit
0
                        ~
                -9
                        ~
        3
                ~
4
                ~
        5
                                ~
                        5
                                ~
                6
                                ~
                        24
                                ~

Process returned 0 (0x0)   execution time : 10.062 s
Press any key to continue.


TEST CASE 2

Enter an integer, zero to quit
5
        ~
5
        ~
Enter an integer, zero to quit
1
        ~
5
                ~
        1
                ~
Enter an integer, zero to quit
3
        ~
5
                        ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
7
                ~
        7
                ~
5
                        ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
9
                        ~
                9
                        ~
        7
                ~
5
                        ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
2
                        ~
                9
                        ~
        7
                ~
5
                        ~
                3
                                ~
                        2
                                ~
        1
                ~
Enter an integer, zero to quit
0
                ~
        1
                                ~
                        2
                                ~
                3
                        ~
5
                ~
        7
                        ~
                9
                        ~

Process returned 0 (0x0)   execution time : 17.834 s
Press any key to continue.


*/


//TreeHeight
//Sanket Joshi
//
//This program will display the numerical height of the tree based off user input into a binary seach tree
//This is a modified version of the code in class and thus doesn't have completely commented code, only the parts added were commented
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
void PrintTree (node *tree);
int TreeHeight (node *root);
node *search (int key, node *tree);
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


    cout << "The height of the tree is " << TreeHeight(root) << endl;

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

node *search (int key, node *tree)
{
    if (tree == NULL || tree -> data == key)
        return tree;
    if (key < tree -> data)
        return search (key, tree -> left);
    else
        return search (key, tree -> right);
}

/***This code is not mine, used simply for formatting and presentation, the two functions padding and strcuture is what I'm referring to***/
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

//Function for height of tree
int TreeHeight (node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lHeight = TreeHeight(root->left);//the left tree height is equal to the tree height at the left root
        int rHeight = TreeHeight(root->right);//the right tree height is equal the the tree height at the right root
        if (lHeight>rHeight)
            return lHeight + 1;//if the left height is greater then the right height, then return the left height of the tree +1

        return rHeight + 1;//return the right height of the tree +1
    }
}

/*TEST CASE
Enter an integer, zero to quit
-4
        ~
-4
        ~
Enter an integer, zero to quit
06
                ~
        6
                ~
-4
        ~
Enter an integer, zero to quit
-6
                ~
        6
                ~
-4
                ~
        -6
                ~
Enter an integer, zero to quit
4
                ~
        6
                        ~
                4
                        ~
-4
                ~
        -6
                ~
Enter an integer, zero to quit
2
                ~
        6
                        ~
                4
                                ~
                        2
                                ~
-4
                ~
        -6
                ~
Enter an integer, zero to quit
6
                        ~
                6
                        ~
        6
                        ~
                4
                                ~
                        2
                                ~
-4
                ~
        -6
                ~
Enter an integer, zero to quit
9
                                ~
                        9
                                ~
                6
                        ~
        6
                        ~
                4
                                ~
                        2
                                ~
-4
                ~
        -6
                ~
Enter an integer, zero to quit
3
                                ~
                        9
                                ~
                6
                        ~
        6
                        ~
                4
                                        ~
                                3
                                        ~
                        2
                                ~
-4
                ~
        -6
                ~
Enter an integer, zero to quit
0
The height of the tree is 5

Process returned 0 (0x0)   execution time : 33.266 s
Press any key to continue.


TEST CASE 2

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
1
                        ~
                6
                        ~
        5
                ~
4
                ~
        1
                ~
Enter an integer, zero to quit
9
                                ~
                        9
                                ~
                6
                        ~
        5
                ~
4
                ~
        1
                ~
Enter an integer, zero to quit
3
                                ~
                        9
                                ~
                6
                        ~
        5
                ~
4
                        ~
                3
                        ~
        1
                ~
Enter an integer, zero to quit
5
                                ~
                        9
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
        1
                ~
Enter an integer, zero to quit
6
                                ~
                        9
                                        ~
                                6
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
        1
                ~
Enter an integer, zero to quit
567
                                        ~
                                567
                                        ~
                        9
                                        ~
                                6
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
        1
                ~
Enter an integer, zero to quit
85
                                        ~
                                567
                                                ~
                                        85
                                                ~
                        9
                                        ~
                                6
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
        1
                ~
Enter an integer, zero to quit
3
                                        ~
                                567
                                                ~
                                        85
                                                ~
                        9
                                        ~
                                6
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
                3
                        ~
        1
                ~
Enter an integer, zero to quit
58
                                        ~
                                567
                                                ~
                                        85
                                                        ~
                                                58
                                                        ~
                        9
                                        ~
                                6
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
                3
                        ~
        1
                ~
Enter an integer, zero to quit
0
The height of the tree is 7

Process returned 0 (0x0)   execution time : 10.681 s
Press any key to continue.

*/

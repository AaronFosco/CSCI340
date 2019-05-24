/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 5    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Friday 3/9/2018 by 11:59PM                              ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||    This is Test file for the binTree class.                   ||
||                                                               ||
||    * * * EDITED FOR ASSIGNMENT 6 * * *                        ||
||    All function definitions were defined in assignmnet5.h,    ||
||   to avoid linker errors, they are moved to this file         ||
||   (should have done this in already in the last assignment...)||
 \_______________________________________________________________/
*/


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

/*
Function::Node, Node

Use: Default constuctor for Node class

Parameters: d: data to be use for this node
*/

Node::Node(int d)
{
   left = nullptr;
   right = nullptr;
   data = d;
}

// Public

/*
Function: binTree, binTree

Use: default constuctor

Parameters: none

Returns: nothing
*/

binTree::binTree()
{
   root = nullptr;
}

/*
Function: insert, binTree

Use: Insert new node at root if root was null
     otherwise it will call the recursive insert function

Parameters: i: value to inialize a new node

Returns: nothing
*/

void binTree::insert(int i)
{
   if (root == nullptr)
      root = new Node(i);
   else
      insert(root, i);
}

/*
Function: hight, binTree

Use: Used to figure out the max depth of the tree at the root

Parameters: none

Returns: the max depth of the tree
*/

int binTree::height() const
{
   int rv;
   if (root == nullptr)
      rv = -1;
   else 
      rv = height(root);
      
   return rv;
}

/*
Function: size, binTree

Use: used to figure out how many nodes are in the tree

Parameters: none

Returns: an unsigned number of nodes in the tree
*/

unsigned binTree::size() const
{
   unsigned rv;
   if (root == nullptr)
      rv = 0;
   else 
      rv = size(root);
      
   return rv;
}

/*
Function: inorder, binTree

Use: calls the recursive inorder function when the root isn't null

Parameters: p: a pointer to a function that will act as "visiting"
               the data in the tree

Returns: nothing
*/

void binTree::inorder(void(* p) (int))
{
   if (root != nullptr)
      inorder(root, p);
}

/*
Function: , binTree

Use: calls the recursive preorder function when the root isn't null

Parameters: p: a pointer to a function that will act as "visiting"
               the data in the tree

Returns:Nothing
*/

void binTree::preorder(void(* p)(int))
{
   if (root != nullptr)
      preorder(root, p);
}

/*
Function: , binTree

Use: calls the recursive postorder function when the root isn't null

Parameters: p: a pointer to a function that will act as "visiting"
               the data in the tree

Returns: nothing
*/

void binTree::postorder(void(* p) (int))
{
   if (root != nullptr)
      postorder(root, p);
}


//private

/*
Function: insert, binTree

Use: Used to insert a new node with value i into the smaller 
     sub-tree

Parameters: r: the current 'root' to a tree/subtree
            i: a value that will be used for the new node

Returns: Nothing
*/

void binTree::insert(Node*& r, int i)
{
   if (r == nullptr)
      r = new Node(i);
   else
   {
      if (r->left != nullptr && r->right != nullptr) // 1 1
      {
         if (size(r->left) > size(r->right))
            insert(r->right, i);
         else
            insert (r->left, i);  
      } else if (r->left == nullptr) // 0 1, 0 0
         insert(r->left, i);
      else //1 0
         insert(r->right, i); 
   }
}

/*
Function: height, binTree

Use: Used to find the max depth of a tree/subtree

Parameters: r: the current 'root' to a tree/subtree

Returns: the Height of the tree/subtree
*/

int binTree::height(Node* r) const
{
   int heightl, heightr;
   if (r == nullptr)
      return 0;
   else
   {
      heightl = height(r->left);
      heightr = height(r->right);
      return (heightl > heightr)? heightr+1 : heightl+1;
   }
   
}

/*
Function: size, binTree

Use: Used to determine the number of nodes in the tree/subtree at
     the 'root'

Parameters: r: the current 'root' of the tree/subtree

Returns: the size of the tree/subtree
*/

unsigned binTree::size(Node* r) const
{
   if (r->left == nullptr && r->right == nullptr)
      return 1;
   else
   {
      unsigned count = 0;
      count += (r->left == nullptr) ? 0 : size(r->left);
      count += (r->right == nullptr) ? 0 : size(r->right);
      return count + 1;
   }
}

/*
Function: inorder, binTree

Use: recursively 'visits' every node using an inorder transversal

Parameters: r: a pointer to a node to visit
            p: a pointer to a function that will act as "visiting"
               the data in the tree

Returns: nothing
*/

void binTree::inorder(Node* r, void(* p) (int))
{
   if (r != nullptr)
   {
      inorder(r->left, p);
      p(r->data);
      inorder(r->right, p);
   }
}

/*
Function: preorder, binTree

Use: recursively 'visits' every node using an preorder transversal

Parameters: r: a pointer to a node to visit
            p: a pointer to a function that will act as "visiting"
               the data in the tree

Returns: nothing
*/

void binTree::preorder(Node* r, void(* p) (int))
{
   if (r != nullptr)
   {
      p(r->data);
      preorder(r->left, p);
      preorder(r->right, p);
   }
}

/*
Function: postorder, binTree

Use: recursively 'visits' every node using an postorder transversal

Parameters: r: a pointer to a node to visit
            p: a pointer to a function that will act as "visiting"
               the data in the tree

Returns: nothing
*/

void binTree::postorder(Node* r, void(* p) (int))
{
   if (r != nullptr)
   {
      postorder(r->left, p);
      postorder(r->right, p);
      p(r->data);
   }
}

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

//#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif

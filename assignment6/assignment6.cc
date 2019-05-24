/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 6    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Friday 3/23/2018 by 11:59PM                             ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||     This is the implementation file for the BST class; it     ||
||     Contains all the function definitions.                    ||
||                                                               ||
||     * * * Incomplete * * *                                    ||
||     This program WILL seg fault.                              ||
 \_______________________________________________________________/
*/

#include <iostream>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

//public

/*
Function: insert, BST

Use: Insert new node at root if root was null
     otherwise it will call the recursive insert function

Parameters: i: value to inialize a new node

Returns: nothing
*/

void BST::insert( int i)
{
   if (root == nullptr)
      root = new Node(i);
   else
      insert(root, i);
}

/*
Function: search, BST

Use: searches for a node with a certain vlaue

Parameters: i: Value of a node to search for

Returns: True if the node was found, false otherwise
*/

bool BST::search( int i)
{
   if (root == nullptr)
      return false;
   else
      return search(root, i);
}

/*
Function: remove, BST

Use: removes a node with a certain value

Parameters: i: value of a node to remove

Returns: True if the removal was sucessful, false otherwise
*/

bool BST::remove( int i)
{
   if (root == nullptr)
      return false;
   else
      return remove(root, i);
}

/*
Function: sumLeftLeaves, BST

Use:Gets the sum of all the Node's values in the left subtree

Parameters: none

Returns: Sum of all Node's values in the left subtree
*/

int BST::sumLeftLeaves()
{
   if (root == nullptr)
      return 0;
   else
      return sumLeftLeaves(root);
}


//private

/*
Function: insert, BST

Use: insert a value into the tree

Parameters:  r: root of the current subtree
             i: value to inialize a new node

Returns: nothing
*/

void BST::insert( Node*& r, int i)
{
   // No repeating numbers, ruling out r->data == i

  if (r->data > i)
  {
      if (r->left == nullptr)
         r->left = new Node(i);
      else
         insert(r->left, i); 
   } else if (r->data < i)
   {
      if (r->right == nullptr)
         r->right = new Node(i);
      else
         insert(r->right, i);
   }
}

/*
Function: search, BST

Use: searches for a node with a certain vlaue

Parameters: r: Root of the current subtree
            i: Value of a node to search for

Returns: True if the node was found, false otherwise
*/

bool BST::search( Node*& r, int i)
{
   bool rv = false;
   
   if (r->data == i)
      rv = true;
   else if (r->data > i)
   {
      if (r->left == nullptr)
         rv = false;
      else
         search(r->left, i);
   }else
   {
      if (r->right == nullptr)
         rv = false;
      else
         search(r->right, i);
   }
   return rv;
}

/*
Function: remove, BST

Use: removes a node with a certain value

Parameters:  r: Root of the current subtree
             i: value of a node to remove

Returns: True if the removal was sucessful, false otherwise
*/

bool BST::remove( Node*& r, int i)
{
   bool rv = false;
   
   if (r == nullptr)
      rv = false;
   else if (r->data > i)
      remove(r->left, i);
   else if (r->data < i)
      remove(r->right, i);
   else
   {
      if (r->left != nullptr && r->right != nullptr)
      {
         Node* hold = r->left;
	 r->data = hold->data;
	 remove(hold, hold->data);
      } else if (r->left == nullptr && r->right == nullptr)
      {
         delete r;
	 r = nullptr;
	 rv = true;
      }else
      {
         Node* hold = r;
	 if (r->left != nullptr)
	    r = r->left;
	 else
	    r = r->right;
	    
	 delete hold;
	 rv = true;
      }
   }
   return rv;
}

/*
Function: sumLeftLeaves, BST

Use:Gets the sum of all the Node's values in the left subtree

Parameters: none

Returns: Sum of all Node's values in the left subtree
*/

int BST::sumLeftLeaves(Node*& r)
{
   if (r == nullptr)
      return 0;
   else
      return ((r->data) + sumLeftLeaves(r->left));
}

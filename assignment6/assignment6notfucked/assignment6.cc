#include <iostream>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

//public
void BST::insert( int i)
{
   if (root == nullptr)
      root = new Node(i);
   else
      insert(root, i);
}

bool BST::search( int i)
{
   if (root == nullptr)
      return false;
   else
      return search(root, i);
}

bool BST::remove( int i)
{
   if (root == nullptr)
      return false;
   else
      return remove(root, i);
}

int BST::sumLeftLeaves()
{
   if (root == nullptr)
      return 0;
   else
      return sumLeftLeaves(root);
}


//private
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

int BST::sumLeftLeaves(Node*& r)
{
   if (r == nullptr)
      return 0;
   else
      return ((r->data) + sumLeftLeaves(r->left));
}

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
||    This is the Header file for both the node class and the    ||
||    the binTree class. The binTree class will mimic a regular  ||
||    binary tree with functions to determine the hight and size ||
||    of the tree as well as inserting new nodes into the tree.  ||
 \_______________________________________________________________/
*/

#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
class Node;

/*
Class: Node

Use: Holds data for itself and the pointers to the right and left
     of itself
*/

class Node {
   public:
      Node(int);
      Node *left;
      Node *right;
      int data;
};

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

/*
Class: binTree

Use: holds a Node(root) that will be used to hold all other nodes
     in a tree. 
     
     Contains functions that will be used to get the height and size
     of the tree, as well as inserting new nodes.
     
     Allows for three types of depth-first traversals
*/

class binTree {
    public:
        binTree();
        virtual void insert( int );
        int height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;

    private:
        void insert( Node*&, int );
        int height( Node* ) const;
        unsigned size( Node* ) const;
	void inorder( Node*, void(*)(int) );
	void preorder( Node*, void(*)(int) );
	void postorder( Node*, void(*)(int) );
};


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

#endif

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
   friend class BST;
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



#endif

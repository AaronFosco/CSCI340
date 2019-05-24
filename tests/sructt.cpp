#include <iostream>
#include <vector>

using namespace std;

class node
{
   public:
      node(int);
      node *left;
      node *right;
      int data;
};

node::node(int data)
{
   node* n = new node;
   n->data = data;
   n->left = nullptr;
   n->right = nullptr;
   return(n);
}


class bintree()
{
   private:
      void insert(int);
      void inorder(node*);
      
   protected:
       node* root;
       
   public:
      bintree();
      void insert(node*&, int);
      void inorder();
}

bintree::bintree()
{
   root = nullptr;
}

void bintree::insert(node*& r, int x)
{
   if (root == nullptr)
      root = node(x);
   else
   {
      
   }
}

void bintree::inorder(node* ptr)
{
   if (ptr != nullptr)
   {
      inorder(ptr->left);
      cout << ptr->data;
      inorder(ptr-right);
   }
}

void bintree::inorder()
{
   inorder(root);
}

int main()
{
   bintree bt;
   vector<node> vn;
   node 
   bt.insert(8);
   bt.insert(4);
   bt.insert(9);
   bt.insert(2);
   bt.insert(5);
   bt.insert(9);
   return 0;
}

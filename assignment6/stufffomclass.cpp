// soruce code for the findnode function

void findnodetodelete(node *& ptr, int val)
{
   if (val < ptr-> data)
      findnodetodelete(ptr->left, val);
   else if (val > ptr -> data
      findnodetodelete(ptr->right, val);
   else if (val == ptr-> data)
      deletenode(ptr);
   else
      cout << "item not found";
}

void deletenode(node *& ptr)
{
   node * hold = ptr;
   
   // case of having no leafs can be merged into the next two ifs
   if (ptr->left == nullptr && ptr-> right == nullptr) 
   {
      ptr = nullptr;
      delete temp;
   } else if (ptr->left == nullptr && ptr-> right != nullptr)
   {
      ptr = ptr->right;
      delete temp;
   } else if (ptr-> right == nullptr)
   {
      ptr = ptr->left;
      delete temp;
   } else if (ptr->left != nullptr && ptr-> right != nullptr)
   {
      getpred(ptr->left, data)
      ptr->data = data;
      deletenode(ptr-left;, data);
   }
}

void getpred(node * ptr, int & val)
{
   while (ptr-> right != nullptr)
      ptr = ptr -> right;
      
   val = ptr->data;

}

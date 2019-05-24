#include <iostream>
#include <vector>
using namespace std;

void print_backwards(vector<int> v)
{
   if (v.size() != 0)
   {
      cout << v.back() << ' ';
      v.pop_back();
      print_backwards(v);
   }
}

int main()
{
   vector<int> v = { 2,4,7 };
   print_backwards(v);
   cout <<endl
   return 0;
   
}

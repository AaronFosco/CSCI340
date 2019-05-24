#include <iostream>
#include <vector>
using namespace std;

int sum_vector(vector<int> v)
{
   if (v.size() != 0)
   {
      int last = v.back();
      v.pop_back();
      return sum_vector(v) + last;
   }
   else
      return 0;
}

int main()
{
   vector<int> v = { 2,7,4 };
   cout << sum_vector(v);
   cout << endl;
   return 0;
   
}

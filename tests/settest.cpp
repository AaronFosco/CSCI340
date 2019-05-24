/*
using "set"
insert 1 - 10
erase 2nd item
erase 3 - 6th item
print the content


*/
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   set<int> s1;
   set<int> :: iterator i1;
   set<int> :: iterator i2;
   
   for (int i = 1; i <= 10; i++)
      s1.insert(i);
    
   i1 = s1.begin();
   i1++;
   i1++;
   s1.erase(i1);
   ///*
   i1 = s1.find(4);
   i2 = s1.find(7);
   if (i1 != s1.end() && i2 != s1.end())
      s1.erase(i1, i2);
   //*/
   /*
   i2 = s1.end();
   i1++;
   i2--;
   i2--;
   i2--;
   
   s1.erase(i1, i2);
   */
   i1 = s1.begin();
   for (int i = 0; i < s1.size(); i++)
   {
      cout << *i1;
      i1++;
   }
   cout << endl;
   return 0;
}

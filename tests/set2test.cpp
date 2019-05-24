#include <iostream>
#include <set>

using namespace std;

int wilson(int);

int main()
{
   set<int> s1;
   set<int> s2;
   for (int i = 1; i <= 10000; i++)
      s1.insert(wilson(i));
      
   /*for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
   {
      if ((*it)% 2 == 0)
      {
         s2.insert(*it);
      }
   }*/
   
   for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
      cout << *it << " ";
      
   cout << endl;
   return 0;
}

int wilson(int n)
{
   long unsigned int hold = n;
   for (int nfact = n-1; nfact != 0; nfact--)
      hold = hold*nfact;
      
   return ((((hold % ( n+1 ) ) /n)*(n-1)) + 2);
}

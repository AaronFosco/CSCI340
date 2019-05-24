#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

bool compaire (int x, int y)
{
   return x<y;

}


int main()
{
   vector<int> v1 = {9, 4, 11};
   list<int> l2 = {5, 7, 9};
   
   sort(v1.begin(), v1.end());
   
   vector<int>::iterator itv;
   itv = v1.begin();
   int lpos = 0, vpos;
   bool done = false;
   while (done == false)
   {
      cout << "vpos is: " << vpos << ", and size of v1: " << v1.size() << endl;
      if (compaire(*itv, l2.front()))
      {
         v1.insert(itv, l2.front());
	 l2.pop_front();
	 itv++;
      } else if (itv != v1.end())
      {
         itv++;
      }
      if (l2.empty())
         done = true;
      
   }
   
   for (int i = 0; i < v1.size(); i++)
      cout << v1[i];
   
   return 0;
}

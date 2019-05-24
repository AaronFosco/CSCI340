#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
char starter = 'a';
char uniout()
{
   return starter++;
}

int main ()
{
   vector<char> v1(26);
   generate(v1.begin(), v1.end(), uniout);
   
   ostream_iterator<char> vout(cout, " ");
   copy(v1.begin(), v1.end(), vout);
   
   //for (vector<char>::iterator vit = v2.begin(); vit != v2.end(); vit++)
     // cout << *vit << ' ';
      
   cout << endl;
   return 0;
}

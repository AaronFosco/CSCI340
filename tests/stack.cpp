#include <stack>
#include <iostream>

using namespace std;

int main()
{
   stack<int> s1;
   
   for (int i = 1; i <= 5; i++)
      s1.push(i);
   
   int counter = 0;
   while (!s1.empty())
   {
      counter += s1.top();
      s1.pop();
   }
      
   cout << "Sum is: " << counter << endl;
   return 0;
}

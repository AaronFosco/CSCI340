#include <iostream>
#include <stack>
using namespace std;

void reverse(stack<int>&);
void remove(stack<int>&, int);

void remove(stack<int>& s1, int x)
{
   stack<int> s2, s3;
   int hold;
   while (!s1.empty())
   {
      s2.push(s1.top());
      s1.pop();
   }
   while (!s2.empty())
   {
      s3.push(s2.top());
      s2.pop();
   }
   while (!s3.empty())
   {
      if (s3.top() != x)
         s1.push(s3.top());
	 
      s3.pop();
   }
}

int main()
{
   stack<int> s1;
   s1.push(1);
   s1.push(2);
   s1.push(3);
   s1.push(1);
   s1.push(5);
   int x = 1;
   remove(s1, x);
   
   while(!s1.empty())
   {
      cout << s1.top() << ' ';
      s1.pop();
   }
   cout << endl;
   return 0;
}

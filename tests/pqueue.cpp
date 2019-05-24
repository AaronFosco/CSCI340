#include <iostream>
#include <queue>

using namespace std;

int main()
{ 
   queue<int> q1;
   queue<int> q2;
   /*q1.push_back(2);
   q1.push_back(5);
   q1.push_back(7);
   q1.push_back(1);
   q1.push_back(9); */
   int hold = 0;
   bool inserted;
   for (int i = 0; i < 5; i++)
   {
      cout << "Enter value: " << endl;
      cin >> hold;
      cout << endl;
      inserted = false;
      while (q1.size() != 0)
      {
         
         if (q1.front() < hold && inserted != true)
         {
	    q2.push(hold);
	    inserted = true;
	 } else
	 {
	    q2.push(q1.front());
	    q1.pop();
	 }
      }
      
      if (inserted == false)
         q2.push(hold);
	 
      q2.swap(q1);
   }
   
   for (; q1.empty() != true; q1.pop())
      cout << q1.front();
      
   cout << endl;
   
   return 0;
}

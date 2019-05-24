#include <iostream>

using namespace std;


template <class T>
void mySwap(T& t1, T& t2)
{
   T thold;
   thold = t1;
   t1 = t2;
   t2 = thold;
}

int main()
{
   int i1 = 5, i2 = 12;
   char c1 = 'A', c2 = 'g';
   double d1 = 3.14, d2 = 2.71;
   cout << i1 << ' ' << i2 << endl;
   cout << c1 << ' ' << c2 << endl;
   cout << d1 << ' ' << d2 << endl;
   
   
   mySwap(i1, i2);
   cout << i1 << ' ' << i2 << endl;
   
   mySwap(c1, c2);
   cout << c1 << ' ' << c2 << endl;
   
   mySwap(d1, d2);
   cout << d1 << ' ' << d2 << endl;

   return 0;
}

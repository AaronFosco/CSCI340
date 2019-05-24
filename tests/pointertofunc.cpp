#include <iostream>
using namespace std;

int add(int x, int y)
{ 
   return (x + y);
}

int subtract (int x, int y)
{
   return (x - y);
}

int operation(int x, int y, int (*aors)(int, int))
{
   return aors(x, y);
}

int main()
{
   int x = operation (5, 3, add);
   int y = operation (20, 15, subtract);
   cout << x << ' ' << y << endl;
   return 0;
}

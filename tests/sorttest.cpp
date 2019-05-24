#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    int hold;
    while (cin >> hold)
    {
       v1.push_back(hold);   
    }

   sort(v1.begin(), v1.end());
   
   for (int i = 0; i < v1.size(); i++)
      cout << v1[i] << "  ";
}

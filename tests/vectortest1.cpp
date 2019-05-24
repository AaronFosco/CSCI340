#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v1;
	vector<int> :: iterator vit;
	for (int i = 2; i <= 10; i = i+2)
	   v1.push_back(i);
	   
	int count = 0;
	
	/*
	NOTES:
	
	vit is an iterator (similar to a pointer), vector.begin()
	returns an iterator to the begining of the vector (first 
	element)
	
	vit's position in memory will be incremented using the ++ 
	operator. this makes it point to the next item in the vector
	
	Finally, vit will be derefrenced to obtain the value it 
	points to for the summation "count".
	*/
	
	for (vit = v1.begin(); vit < v1.end(); vit++)
	   count += *vit;
	   
	cout << count << endl;
	return 0;
}

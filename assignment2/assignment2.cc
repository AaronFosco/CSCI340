/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 2    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Tuesday 2/6/2018 by 11:59PM                             ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||       This is the Main implementation file for assignment 2.  ||
||       This Program will use a linear search and a binary      ||
||       search to see if certain items exist in a vector.       ||
||       the number of times an item is found is recorded to     ||
||       determine the number of successful searchs of each      ||
||       algorithm when the vector is unsorted and sorted.       ||
 \_______________________________________________________________/
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

//universal Consts to make the output the same for every execution

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

/*
Function: genRndNums

Usage: Fills a vector to its max capacty with intergers from 1-100

Parameters: v: a vector to fill
            seed: a seed that will be used to generate random
	    numbers

Returns: nothing
*/

void genRndNums( vector<int>& v, int seed ) {
   srand(seed);
   int fillto = v.capacity();
   for (int i = 0; i < fillto; i++)
      v[i] = (rand()%100+1);
}

/*
Function: linearSearch

Usage: Uses find() to perform a linear search thru a vector

Parameters: inputVec: a vector of int that should be filled & will
                      be used as the container to search through
		      
            x: an item that will be searched for in the container 

Returns: true if the item was found, false otherwise
*/

bool linearSearch( const vector<int>& inputVec, int x) {
   vector<int>::const_iterator vit;
   vit = find(inputVec.begin(), inputVec.end(), x);
   return (vit != inputVec.end());
}

/*
Funciton: binarySearch

Usage: Uses binary_search() to perform a binary search tru a vector

Parameters: inputVec: a vector of int that should be filled & will
                      be used as the container to search through
		      
            x: an item that will be searched for in the container 

Returns: true if the item was found, false otherwise
*/

bool binarySearch( const vector<int>& inputVec, int x) {
   return binary_search(inputVec.begin(), inputVec.end(), x);
}

/*
Function: search

Useage: Search thru a vector for an item using a function that was
        passed to the function at the time of the function call
	
Parameters: inputVec: a vector of int that should be filled & will
                      be used as the container to search through
            
	    searchVec: a vector of int that should be filled & each
	               item contained within will attempted to be 
		       found in inputVec
		       
            p: a pointer to a function. This should be a type of 
	       search function
	       
Retuns: the ammount of times the item in searchVec was found in
        inputVec

*/

int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) ){
   vector<int>::const_iterator it;
   int count = 0;
   for (it = searchVec.begin(); it != searchVec.end(); it++)
      (p(inputVec, *it)? count++ : 0);
   return count;
}

/*
Function: sortVector

Usage: Uses sort() to sort a vector

Parameters: inputVec: a vector to sort

Returns: nothing
*/

void sortVector (vector<int>& inputVec) {
   sort(inputVec.begin(), inputVec.end());
}

void printStat (int totalSucCnt, int vec_size) {
   cout << "Successful searches: " 
        << fixed << setprecision(2)
	<< ((double (totalSucCnt)) / (double (vec_size)))*100
	<< '%' << endl;
}

/*
Function: print_vec

Use: Outputs the contents of a vector onto cout with extra
     formmating
     
Parameters: vec: a vector that will have it's contents displayed

Returns: nothing
*/

void print_vec( const vector<int>& vec ){

   int size = vec.size();
   for (int index = 0; index < size; index++)
   {
      if (index % 10 == 0 && index != 0)
         cout << endl;
      
      cout << setw(6) << vec[index];
   }
   
   cout << endl;
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}


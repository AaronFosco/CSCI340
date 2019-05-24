/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 1    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Monday 1/29/2018 by 11:59PM                             ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||       This is the Main implementation file for assignment 1.  ||
||       This Program will use a linear search and a binary      ||
||       search to see if certain items exist in a vector.       ||
||       the number of items found and the number of comparisons ||
||       are recorded to determine the effciency & accuracy of   ||
||       each algorithm when the vector is unsorted and sorted   ||
 \_______________________________________________________________/
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

//universal Consts to make the output the same for every execution

const int DATA_SIZE = 200;
const int DATA_RANGE = 200;
const int DATA_SEED = 9;
const int SEARCH_SEED = 17;

/*
Function: linear_search

Usage: uses a linear search algorithm to search though a vector for
       an item. It will also record the ammount of times a 
       comparison took place.

Parameters: inputVec: a vector of int that should be filled & will
                      be used as the container to search through
		      
            x: an item that will be searched for in the container 
	    
	    comparisons: the number of compairsons between the item
	                 that will be searched for and an item in 
			 the container

Returns: the index of "x"'s value in the container "inputVec".
         if "x" doesn't exsist in the container, it returns -1
*/

int linear_search(const vector<int>& inputVec, const int x, int& comparisons) {

   comparisons = 0;
   int size = inputVec.size(), rv = -1;
   
   //Check to see if the container is empty
   
   if (size != 0)
   {
      
      //linear search algorithm
      
      int index = 0;
      while (index < size)
      {
         if(inputVec[index] == x)
	 {
	    rv = index;
	    index = size;
	 }
	 comparisons++;
	 index++;
      }
   }
   
   return rv;
}

/*
Function: binary_search

Usage: uses a binary search algorithm to search though a vector for
       an item. It will also record the ammount of times a 
       comparison took place.

Parameters: inputVec: a vector of int that should be filled & will
                      be used as the container to search through
		      
            x: an item that will be searched for in the container 
	    
	    comparisons: the number of compairsons between the item
	                 that will be searched for and an item in 
			 the container

Returns: the index of "x"'s value in the container "inputVec".
         if "x" doesn't exsist in the container, it returns -1
*/

int binary_search(const vector<int>& inputVec, const int x, int& comparisons) {


   comparisons = 0;
   int size = inputVec.size(), rv = -1;
   bool flag = false;
   
   //Check to see if container is empty
   
   if (size != 0)
   {
      //Binary search algorithm 
      
      int left = 0, right = size, midpoint;
      while (flag == false)
      {
         midpoint = ((left+right)/2);
	 if (left != right && left < right)
	 {
   	    if (inputVec[midpoint] > x)
	    {
	       comparisons++;
	       right = midpoint;
	    } else if (inputVec[midpoint] < x)
	    {
	       comparisons++;
	       left = midpoint+1;
	    } else if(inputVec[midpoint] == x)
	    {
	        comparisons++;
		rv = midpoint;
	        flag = true;
            }
	 } else 
	 {
	    flag = true;
	 }
      }
   }
   
   return rv;
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
      if (index % 8 == 0 && index != 0)
         cout << endl;
      
      cout << setw(4) << vec[index];
   }
   
   cout << endl;
}

void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, int (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison = 0, sum = 0, found = 0;
    int res = 0;
    for (i = 0; i < (int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res >= 0 )
           found++;
    }
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

int random_number() {
    return rand()%DATA_RANGE + 1;
}

int main () {

    // -------- create unique random numbers ------------------//
    vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl;
    print_vec(inputVec);
    cout << endl;

    // -------- create random numbers to be searched ---------//
    vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
    print_vec(searchVec);
    cout << endl;

    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    cout << "------- numbers in data source are now sorted ---------" << endl << endl;
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}

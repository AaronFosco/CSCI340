#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

void genRndNums( vector<int>& v, int seed ) {
   srand(seed);
   int fillto = v.capacity();
   for (int i = 0; i < fillto; i++)
      v.push_back(rand()%100+1);
}

bool linearSearch( const vector<int>& inputVec, int x) {
   vector<int>::iterator vit;
   vit = find(inputVec.begin(), inputVec.end(), x);
   return (vit == inputVec.end-1);
}

bool binarySearch( const vector<int>& inputVec, int x) {
   return find(inputVec.begin(), inputVec.end(), x);
}

int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) ){
   vector<int>::iterator it;
   int count = 0;
   for (it = searchVec; it != searchVec.end(); it++)
      (p(inputVec, *it)? count++ : 0);
   return count;
}

void sortVector (vector<int>& inputVec) {
   sort(inputVec);
}

void printStat (int totalSucCnt, int vec_size) {
   cout << ((double (totalSucCnt)) / (double (Vec_size)));
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


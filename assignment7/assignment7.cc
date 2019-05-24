/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 7    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Friday  4/6/2018 by 11:59PM                             ||
||                                                               ||
||  Extra credit Due-date: Wednesday 4/4/2018 by 11:59PM         ||
||                                                               ||
||  Description:                                                 ||
||      This Program will Emulate a heap by using a linear       ||
||      storage type (vector) and a few specific algorithms.     ||
||      This program also is able to conduct a max and min       ||
||      heapify, as well as a heapsort.                          ||
||                                                               ||
 \_______________________________________________________________/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "assignment7.h"

using namespace std;

/*
Function: build_heap

Use: sorts a vector to be in a logical min or max heap

Parameters: v: a refrence to a vector to be max or min heapifed
            heap_size: the logical size of the heap
	    compar: a refrence to a function, either less_than or
	            greater_than in this program's main() case

Returns: nothing
*/

void build_heap(vector <int> & v, int heap_size, bool (*compar) (int, int))
{
   for (int i = heap_size; i > 0; i--)
      heapify(v, heap_size, i, compar);
}

/*
Function: heapify

Use: sorts a vector to be in a logical min or max heap based on a 
     logical tree/subtree with root r

Parameters:v: a refrence to a vector to be max or min heapifed
            heap_size: the logical size of the heap
	    r: the current root of the logical tree/subtree
	    compar: a refrence to a function, either less_than or
	            greater_than in this program's main() case

Returns: nothing
*/

void heapify(vector <int> & v, int heap_size, int r, bool (*compar) (int, int))
{
   //one child
   if ((2*r) == heap_size)
   {
      if (compar(v[2*r], v[r]))
      {
         int hold = v[2*r];
      	 v[2*r] = v[r];
	 v[r] = hold;
	 heapify(v, heap_size, 2*r, compar);
      }
   } else if ((2*r + 1) < heap_size) //two childen
   {
      if (compar(v[2*r], v[2*r + 1]))
      {
         if (compar(v[2*r], v[r]))
         {
            int hold = v[2*r];
      	    v[2*r] = v[r];
	    v[r] = hold;
	    heapify(v, heap_size, 2*r, compar);
         } 
      } else
      {
         if (compar(v[2*r + 1], v[r]))
         {
            int hold = v[2*r + 1];
	    v[2*r + 1] = v[r];
	    v[r] = hold;
	    heapify(v, heap_size, 2*r+1, compar);
         } 
      }
   }
}

/*
Function: less_than

Use: compairs two varables

Parameters: e1: a number to be compaired
            e2: a number to be compaired

Returns: true if e1 was less than e2, false otherwise
*/

bool less_than(int e1, int e2)
{
   return (e1 < e2) ? true : false ;
}


/*
Function: greater_than

Use: compairs two varables

Parameters: e1: a number to be compaired
            e2: a number to be compaired

Returns: true if e1 was greater than e2, false otherwise
*/

bool greater_than(int e1, int e2)
{
   return (e1 > e2) ? true : false ;
}

/*
Function: heap_sort

Use: Conducts a heap sort on a vector organized as a min or max heap
     
Parameters: v: a refrence vector to conduct a heapsort on (first
               physical element is ignored)
	    heap_size: the logical size of the heap
      	    compar: a refrence to a function, either less_than or
	            greater_than in this program's main() case

Returns: nothing
*/

void heap_sort(vector <int> & v, int heap_size, bool (*compar) (int, int))
{
   while (heap_size > 0)
      extract_heap(v, heap_size, compar);
      
   reverse(v.begin()+1, v.end());
}

/*
Function: extract_heap

Use: Conducts a heapsort on a vector organized as a min or max heap

Parameters: v: a refrence vector to conduct a heapsort on (first
               physical element is ignored)
	    heap_size: the logical size of the heap. This doesn't 
	               count the sorted elements
      	    compar: a refrence to a function, either less_than or
	            greater_than in this program's main() case

returns: The previous value that was at the root
*/

int extract_heap(vector <int> & v, int& heap_size, bool (*compar) (int, int))
{
   int hold = v[1];
   v[1] = v[heap_size];
   v[heap_size] = hold;
   heapify(v, --heap_size, 1, compar);
   return hold;
}

/*
Function: print_vector

Use: prints the contents of a vector at a given position up to a 
     given size

Parameters: v: vector to print
            pos: position to start printing elements
	    size: number of elements to print starting from pos 

returns: nothing
*/

void print_vector(vector <int> & v, int pos, int size)
{
   int rcount = 0;
   while (size != 0)
   {
      cout << setw(5) << v[pos];
      rcount++;
      pos++;
      size--;
      if (rcount == 8)
      {
         cout << endl;
	 rcount = 0;
      }
   }
   cout << endl;
}

const int HEAP_SIZE = 50;

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}

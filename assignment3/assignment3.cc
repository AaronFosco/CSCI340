/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 3    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Tuesday 2/14/2018 by 11:59PM                            ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||       This is the Main implementation file for assignment 3.  ||
||       This Program will Prompt the user for a range and       ||
||       Calculate all prime numbers within the range using an   ||
||       algorithm known as the "Sieve of Eratosthenes".         ||
 \_______________________________________________________________/
*/

#include <iostream>
#include <set>
#include <string>
#include <iomanip>

using namespace std;

/*
Function: sieve

Usage: Fills a set from lower (or 2 if lower=<2) to upper & 
       executes the "Sieve of Eratosthenes" algorithm 

Parameters: s: a set to be filled and sieved
            lower: lower bounds of numbers to sieve
	    upper: upper bounds of numbers to sieve

Returns: nothing
*/

void sieve( set<int>& s, const int lower, const int upper) {

   bool finished = false;
   int m = 2, k;
   int count = (lower >= 2)? lower : 2; 
   set<int>::iterator sit = s.begin();
   
   //insert elements from lower (or 2 if lower=<2) to upper into s
   
   while (count <= upper)
   {
      sit = s.insert(sit, count);
      count++;
   }
   
   //execute Sieve of Eratosthenes
   
   while (finished == false)
   {
      k = m;
      for (k = m; k*m <= upper; k++)
      {
         sit = s.find(k*m);
	 if (sit != s.end())
	    s.erase(sit);
      } 
      
      m++;
      
      if ((m*m) >= upper)
         finished = true;
   }
      
}

/*
Function: print_primes

Usage: prints out the contents of s onto cout with formatted output

Parameters: s: the set to print out
            lower: lower bounds of numbers to sieve
	    upper: upper bounds of numbers to sieve
	    
Returns: nothing
*/

void print_primes( const set<int>& s, const int lower, const int upper) {

   cout << "There are " << s.size() 
        << " prime numbers between "
	<< lower << " and " << upper << ":\n";
   
   //iterate thru set with formatted output
   
   set<int>::iterator sit;
   int count = 0;
   for (sit = s.begin(); sit != s.end(); sit++)
   {
      if (count % 6 == 0 && count != 0)
         cout << endl;
	 
      cout << setw(5) << *sit;
      count++;
   }
   cout << endl << endl;
}

void run_game(set<int>& s) {

   bool contin = true;
   string response;
   int lower, upper;
   while (contin == true)
   {
      //User Input with  (slight) error handling
      
      cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100):" << endl;
      cin >> lower >> upper;
      while (upper < lower)
      {
         cout << "Please enter a correct range: ";
	 cin >> lower >> upper;
      }
      
      //Process input
      
      sieve(s, lower, upper);
      print_primes(s, lower, upper);
      
      //reset s for future use or pre-emptive memory clearing
      
      s.clear();
      
      //more user input for continuing or not, with error handling 
      
     cout << "Do you want to continue or not? Please answer yes or no and hit enter:" << endl;
     cin >> response;
     
     while (response != "yes" && response != "no")
     {
        cout << "Please enter yes or no: " << endl;
	cin >> response;
     }
     
     if (response == "yes") {}
     else if (response == "no")
        contin = false;
   }
}

/*
Function: main

Usage: Used to start the program by running run_game

Parameters: none

Returns: 0 if sucessful
*/

int main() {
    set<int> s;
    run_game(s);
    return 0;
}

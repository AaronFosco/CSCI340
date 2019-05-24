/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 4    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Thursday 2/22/2018 by 11:59PM                           ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||    This is the main function as well as method implimentation ||
||    for assignment 4. It will simulate A Queue ADT by using    ||
||    The Stack ADT from the STL.                                ||
 \_______________________________________________________________/
*/

#include <iostream>
#include <iomanip>

#include "assignment4.h"

using namespace std;
int main() {
    Queue q;
    string op;
    int val = 0;
 
   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            q.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
        cin >> op;
    }

    while ( !q.empty() )
        q.pop();

    return 0;
}

/*
Function: empty, Queue Class

Use: figure out if the queue is empty

Parameters: none

Returns: true if the queue is empty, false otherwise
*/

bool Queue::empty() const
{
   return ( s1.empty() && s2.empty() );
}

/*
Function: size, Queue Class

Use: used to get the size of the queue

Parameters: none

Returns: the size of the queue
*/

int Queue::size() const
{
   return ( s1.size() + s2.size() );
}

/*
Function: front, Queue Class

Use: used to get the oldest element in the queue

Parameters: none

Returns: the oldest element in the queue
*/

int Queue::front()
{
   if (s2.empty())
   {
      while (!s1.empty())
      {
         s2.push(s1.top());
	 s1.pop();
      }
   }
   return s2.top();
}

/*
Function: back, Queue Class

Use: used to get the newest element in the queue

Parameters: none

Returns: the newest element in the queue
*/

int Queue::back()
{
   return s1.top();
}

/*
Function: push, Queue Class

Use: push an element to the top of the queue

Parameters: val: refrence to a constant int that will be inserted
                 into the queue

Returns: Nothing
*/

void Queue::push(const int& val)
{
   s1.push( val );
}

/*
Function: pop, Queue Class

Use:Removes the oldest element in the Queue

Parameters: None

Returns: Nothing
*/

void Queue::pop()
{
   front();
   s2.pop();
}

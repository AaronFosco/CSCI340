/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 9    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Friday 4/27/2018 by 11:59PM                             ||
||                                                               ||
||  Description:                                                 ||
||                                                               ||
||       This is the implementation file for assignment9. This   ||
||       assignment will implment a way to conver an ajacency    ||
||       matrix into a ajacency list and then perform depth      ||
||       first transversal.                                      ||
 \_______________________________________________________________/
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "assignment9.h"
using namespace std;

bool *visited;
vector<string> vp;

//public

/*
Constuctor: graph

Use: Creates a new graph by using a file

Parameters: filename: the name of a file to take input from
*/

graph::graph( const char* filename )
{
   ifstream inFile;
   
   inFile.open(filename);
   if (!inFile)
   {
      cerr << "Unable to open input file";
      exit(1);
   }
   
   inFile >> this->size;
   
   //ignore newln
   inFile.ignore();
   
   //both casted to a long int since 
   //labels.size returns a unsigned int
   while ((long int)labels.size() < (long int)size)
   {
      //ignore tabs
      inFile.ignore();
      
      labels.push_back(inFile.get());
   }
   //ignore newln
   inFile.ignore();
   
   
   list<int> *hold;
   
   for (int i = 0; i < size; i++)
   {
      //ignore Char+tab
      inFile.ignore(2);
      
      hold = new list<int>;
      adj_list.push_back(*hold);
      
      for (int j = 0; j < size; j++)
      {
      
         //if a 1 is found, push back the current place in this loop
         if (inFile.get() == '1')
            adj_list[i].push_back(j);
	    
	 //ignore tab or newln
	 inFile.ignore();
      } 
   }
   
   inFile.close();
} 

/*
Deconstuctor: graph

Use: De-allocates dynamically alocated objects
*/

graph::~graph()
{
   while (!adj_list.empty())
      adj_list.pop_back();
}

/*
Function: traverse, graph

Use: traverses a graph by calling depth_first()

Parameters: none

Returns: nothing
*/

void graph::traverse()
{

   visited = new bool[size-1];
   for (int i = 0; i < size;i++)
      visited[i] = 0;
      
   
   cout << "\n------- travere of graph ------\n";
   depth_first(0);
   
   //double check to see if the graph isn't connected
   bool done = false;
   int pos;
   while (!done)
   {
      pos = -1;
      for (int i = 0; i < size;i++)
      {
         if (visited[i] == 0 && pos == -1)
	    pos = i;
      }
      if (pos != -1)
         depth_first(pos);
      else
         done = true;
   }
    
   cout << endl;
   for (vector<string>::iterator it = vp.begin(); it != vp.end();it++)
      cout << *it;
   cout << "\n--------- end of traverse -------\n\n";
   delete visited;
}

/*
Function: print, graph

Use: prints out the number of verties in the graph as well as the
     full adjacency list

Parameters: none

Returns: nothing
*/

void graph::print() const
{
   cout << "\nNumber of vertices in the graph: " << size;
   cout << "\n\n-------- graph -------\n";
   for (int i = 0; i < size; i++)
   {
      cerr << labels.at(i);
      cerr << ": ";
      for (list<int>::const_iterator it = adj_list[i].begin(); it != adj_list[i].end(); it++)
         cerr << labels[*it] << ", ";
  
      cerr << endl;   
   }
   cout << "------- end of graph ------\n";
}

//private

/*
Function: depth_first, graph

Use: Preforms a recursive depth first search on a graph based on its
     adjacnecy list. Must be called more than once if the graph is 
     not connected

Parameters: v: A visited vertex that will be used to traverse the 
               graph

Returns: nothing
*/

void graph::depth_first(int v)
{
   cout << labels[v] << ' ';
   visited[v] = 1;
   list<int>::iterator hold;
   for(int i = 0; i < size; i++)
   {
      
      hold = find(adj_list[v].begin(), adj_list[v].end(), i);
      if (!visited[i] && *hold == i && hold != adj_list[v].end())
      {
         string s = "(";
	 s += (char)labels[v];
	 s += ", ";
	 s += (char)labels[i];
	 s += ") ";
         vp.push_back(s);
         depth_first(i); 
      }     
   }
}

#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }
    
    graph g(argv[1]);

    g.print();
    
    g.traverse();
    
    return 0;
}

#endif

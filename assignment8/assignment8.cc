/*
  _______________________________________________________________
 /                                                               \
||  Course: CSCI-340    Assignment #: 8    Semester: Spring 2018 ||
||                                                               ||
||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
||                                                               ||
||  TA's Name: Saurabh Chitre                                    ||
||                                                               ||
||  Due: Wednesday 4/18/2018 by 11:59PM                          ||
||                                                               ||
||  Extra credit Due-date: Monday 4/16/2018 by 11:59PM           ||
||  Description:                                                 ||
||                                                               ||
||     This is the main file for assignment 8. Assignment8.h and ||
||     the main function in this file are left untouched. This   ||
||     program is suppose to simulate a mini hash table and hash ||
||     function with collision handling based on a linear probe  ||
||     algorithm.                                                ||
 \_______________________________________________________________/
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "assignment8.h"

using namespace std;

/*
Constructor: HT

Use: default Constuctor for HT

Parameters: size: the size of the desired hash table (defult = 11)
*/

HT::HT(int size=11)
{
   hTable = new vector<Entry>(size);
   table_size = size;
   item_count = 0;
}

/*
Deconstuctor: HT

Use: Deconstuctor for HT class

Parameters: none
*/

HT::~HT()
{
   delete hTable;
}

/*
Function: insert, HT

Use: inserts an entry into the hash table 

Parameters: ent: an entry to insert

Returns: false if the insert was unsucessful or if the table was full, true otherwise
*/

bool HT::insert(const Entry& ent)
{
   bool rv = false;
   
   //If the entry is already in the table, exit
   if (search(ent.key) == -1)
   {
      int ipos = hashing(ent.key), hpos;
      for (int i = 0; i <= item_count; i++)
      {
      
         //Position in table, respecting table size
         hpos = (ipos+i)%table_size;
	 
         //If the spot is empty, insert
         if (hTable->at(hpos).key == "---" || hTable->at(hpos).key == "+++")
	 {
	    rv = true;
	    hTable->at(hpos) = ent;
	    item_count++;
	    i = item_count+1;
	 }
      }
   } else
      cout << "Item already in table!\n";
      
   return rv;
}

/*
Function: search, HT

Use: Searches for an entry with a given key

Parameters: key: the key to a given entry to look for

Returns: the position in the hash table
*/

int HT::search(const string& key)
{
   int rv = -1, hpos, ipos;
   ipos = hashing(key); 
   
   //Linear Probing up to item_count times
   for (int i = 0; i <= item_count; i++)
   {
   
      //Position in table, respecting table size
      hpos = (ipos+i)%table_size;
      
      //If the key found was default exit immediately
      if (hTable->at(hpos).key == "---")
         i = item_count+1;
      else
      {	 
         //if the key was found
         if (hTable->at(hpos).key == key)
         {
	    rv = hpos;
	    i = item_count+1;
	 }
      }
   }
   return rv;
}

/*
Function: remove, HT

Use: removes an entry with a given key

Parameters: key: the key to an entry to remove

Returns: true if the remove was sucessful, false otherwise
*/

bool HT::remove(const string& key)
{
   bool rv = false;
   int hpos = search(key);
   if (hpos != -1)
   {
      rv = true;
      hTable->at(hpos).key = "+++";
      item_count--;
   } 
   return rv;
}

/*
Function: print, HT

Use: Prints the contents of a hash table

Parameters: none

Returns: nothing
*/

void HT::print()
{
   cout << "\n----Hash Table-----\n";
   for (int i = 0; i < table_size; i++)
   {
      if (hTable->at(i).key != "---" && hTable->at(i).key != "+++")
      {
         cout << setw(2) << i << ": ";
	 cout << setw(3) << hTable->at(i).key << ' ';
	 cout << hTable->at(i).description << endl;
      }
   }
   cout << "-------------------\n\n";
}

/*
Function: get_entry

Use: creates a new entry based on a line of input

Parameters: line: a line of input to create an entry

Returns: a new entry
*/

Entry* get_entry (const string& line)
{
   Entry* nent = new Entry();
   nent->key = line.substr(2, 3);
   nent->description = line.substr(6, string::npos);
   return nent;
}

/*
Function: get_key

Use: gets the key from a line of input

Parameters: line: a line of input to get the key from

Returns: a key from a line of input
*/

string get_key (const string& line)
{
   return line.substr(2, 3);
}

// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   int rv = ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
   return rv;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
	    Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}

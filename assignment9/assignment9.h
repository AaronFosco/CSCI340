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
||      This is the header file for assignment9.                 ||
 \_______________________________________________________________/
*/

#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>

class graph {
    private:
        int size;
        std::vector< std::list<int> > adj_list;
        std::vector< char > labels;
        void depth_first( int );
    public:
        graph( const char* filename );
        ~graph();
        int get_size() const { return size; };
        void traverse( ) ;
        void print ( ) const;
};

#endif 

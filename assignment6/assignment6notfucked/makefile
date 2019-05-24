#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-340    Assignment #: 6    Semester: Spring 2018 ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
#||                                                               ||
#||  TA's Name: Saurabh Chitre                                    ||
#||                                                               ||
#||  Due: Friday 3/23/2018 by 11:59PM                             ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for assignment 6.                    ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment6: assignment5.o assignment6.o assignment6main.o
	g++ $(CCFLAGS) -o assignment6.exe assignment5.o assignment6.o assignment6main.o

# Rules to compile source code file to object code
assignment5.o: assignment5.cc assignment5.h
	g++ $(CCFLAGS) -c assignment5.cc

assignment6.o: assignment6.cc assignment6.h assignment5.h
	g++ $(CCFLAGS) -c assignment6.cc
	
assignment6main.o: assignment6main.cc assignment6.h assignment5.h
	g++ $(CCFLAGS) -c assignment6main.cc
	
# Header file dependency
assignment6.h: assignment5.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment6.exe

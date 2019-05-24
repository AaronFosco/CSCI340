#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-340    Assignment #: 3    Semester: Spring 2018 ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
#||                                                               ||
#||  TA's Name: Saurabh Chitre                                    ||
#||                                                               ||
#||  Due: Tuesday 2/14/2018 by 11:59PM                             ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for assignment 3.                    ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment3: assignment3.o
	g++ $(CCFLAGS) -o assignment3.exe assignment3.o

# Rules to compile source code file to object code
assignment3.o: assignment3.cc
	g++ $(CCFLAGS) -c assignment3.cc

# Header file dependency

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment3.exe

#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-340    Assignment #: 1    Semester: Spring 2018 ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
#||                                                               ||
#||  TA's Name: Saurabh Chitre                                    ||
#||                                                               ||
#||  Due: Monday 1/29/2018 by 11:59PM                             ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for assignment 1.                    ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment1: assignment1.o
	g++ $(CCFLAGS) -o assignment1.exe assignment1.o

# Rules to compile source code file to object code
assignment1.o: assignment1.cpp
	g++ $(CCFLAGS) -c assignment1.cpp

# Header file dependency

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment1.exe

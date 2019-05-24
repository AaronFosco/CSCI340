#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-340    Assignment #: 4    Semester: Spring 2018 ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
#||                                                               ||
#||  TA's Name: Saurabh Chitre                                    ||
#||                                                               ||
#||  Due: Thursday 2/22/2018 by 11:59PM                           ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for assignment 4.                    ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment4: assignment4.o
	g++ $(CCFLAGS) -o assignment4.exe assignment4.o

# Rules to compile source code file to object code
assignment4.o: assignment4.cc assignment4.h
	g++ $(CCFLAGS) -c assignment4.cc

# Header file dependency

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment4.exe

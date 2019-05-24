#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-340    Assignment #: 9    Semester: Spring 2018 ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
#||                                                               ||
#||  TA's Name: Saurabh Chitre                                    ||
#||                                                               ||
#||  Due: Friday 4/27/2018 by 11:59PM                             ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for assignment 9.                    ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment9: assignment9.o
	g++ $(CCFLAGS) -o assignment9.exe assignment9.o

# Rules to compile source code file to object code
assignment9.o: assignment9.cc assignment9.h
	g++ $(CCFLAGS) -c assignment9.cc
	
# Header file dependency

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment9.exe

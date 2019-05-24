#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-340    Assignment #: 8    Semester: Spring 2018 ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
#||                                                               ||
#||  TA's Name: Saurabh Chitre                                    ||
#||                                                               ||
#||  Due: Wednesday 4/18/2018 by 11:59PM                          ||
#||                                                               ||
#||  Extra credit Due-date: Monday 4/16/2018 by 11:59PM           ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for assignment 8.                    ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment8: assignment8.o
	g++ $(CCFLAGS) -o assignment8.exe assignment8.o

# Rules to compile source code file to object code
assignment8.o: assignment8.cc assignment8.h
	g++ $(CCFLAGS) -c assignment8.cc
	
# Header file dependency

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment8.exe

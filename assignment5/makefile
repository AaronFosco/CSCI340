#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-340    Assignment #: 5    Semester: Spring 2018 ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
#||                                                               ||
#||  TA's Name: Saurabh Chitre                                    ||
#||                                                               ||
#||  Due: Friday 3/9/2018 by 11:59PM                              ||
#||                                                               ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for assignment 5.                    ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment5: assignment5.o
	g++ $(CCFLAGS) -o assignment5.exe assignment5.o

# Rules to compile source code file to object code
assignment5.o: assignment5.cc assignment5.h
	g++ $(CCFLAGS) -c assignment5.cc

# Header file dependency

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment5.exe

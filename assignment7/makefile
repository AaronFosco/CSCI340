#  _______________________________________________________________
# /                                                               \
#||  Course: CSCI-340    Assignment #: 7    Semester: Spring 2018 ||
#||                                                               ||
#||  NAME:  Aaron Fosco    Z-ID: z1835687     Section: 1          ||
#||                                                               ||
#||  TA's Name: Saurabh Chitre                                    ||
#||                                                               ||
#||  Due: Friday  4/6/2018 by 11:59PM                             ||
#||                                                               ||
#||  Extra credit Due-date: Wednesday 4/4/2018 by 11:59PM         ||
#||  Description:                                                 ||
#||                                                               ||
#||     This is the makefile for assignment 7.                    ||
# \_______________________________________________________________/

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment7: assignment7.o
	g++ $(CCFLAGS) -o assignment7.exe assignment7.o

# Rules to compile source code file to object code
assignment7.o: assignment7.cc assignment7.h
	g++ $(CCFLAGS) -c assignment7.cc
	
# Header file dependency

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment7.exe

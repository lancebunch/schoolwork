###############################################################
# Program:
#     Lab 08, OpenMP
#     Brother Ball, CS345
# Author:
#     Lance Bunch
# Summary:
#     This is to practice using the OpenMP thread data
# Time:
#     Estimated: 5.0 Hrs
#		Actual:	  0.0 Hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab08.cpp
	g++ -o a.out -fopenmp lab08.cpp 
	tar -czf lab08.tar makefile lab08.cpp

sampleVariableThreads.out: sampleVariableThreads.cpp
	g++ -o sampleVariableThreads.out -fopenmp sampleVariableThreads.cpp

all: a.out sampleVariableThreads.out
	

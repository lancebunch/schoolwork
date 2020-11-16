###############################################################
# Program:
#     Lab 07, Producer & Consumer Lab
#     Brother Ball, CS345
# Author:
#     Lance Bunch
# Summary:
#     This program demonstrates the use of threads and
#		implements thread safety procedures that protect
#		against the critical-section problem such as Mutex Locks
#		and Semaphores
# Time:
#     Estimated: 6.0 Hrs
#		Actual:	  7.0 Hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab06.cpp cars.h
	g++ -o a.out lab06.cpp -lpthread
	tar -czf lab06.tar makefile lab06.cpp cars.h

sampleMutex.out: sampleMutex.cpp
	g++ -o sampleMutex.out -lpthread sampleMutex.cpp

sampleBinarySem.out: sampleBinarySem.cpp
	g++ -o sampleBinarySem.out -lpthread sampleBinarySem.cpp

sampleCountSem.out: sampleCountSem.cpp
	g++ -o sampleCountSem.out -lpthread sampleCountSem.cpp

all: a.out sampleMutex.out sampleBinarySem.out sampleCountSem.out
	

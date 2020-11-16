###############################################################
# Program:
#     Week 04, DEQUE
#     Brother Ercanbrack, CS235
# Author:
#     Lance Bunch
# Summary:
#     This is the implementation of the Deque ADT.
# Time:
#     3.0 Hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h week04.o nowServing.o
	g++ -o a.out week04.o nowServing.o -std=c++11
	tar -cf week04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week04.o       : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
week04.o: deque.h week04.cpp
	g++ -c week04.cpp -std=c++11

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp -std=c++11

###############################################################
# Program:
#     Lab 04, Scheduling Lab
#     Brother Ball, CS345
# Author:
#     Lance Bunch
# Summary:
#     This program showcases various scheduling algorithms
#		such as the Round Robin, Shortest-Job First, and
#		Shortest Remaining Time
# Time:
#     Estimated: 6.0 Hrs
#		Actual: 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab04.o schedule.o
	g++ -o a.out lab04.o schedule.o
	tar -j -cf lab04.tar makefile *.cpp *.h

##############################################################
# The individual components
##############################################################
lab04.o: lab04.cpp schedule.h 
	g++ -c lab04.cpp

schedule.o: schedule*.h schedule.cpp process.h
	g++ -c schedule.cpp


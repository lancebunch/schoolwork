###############################################################
# Program:
#     Lab 10, Page Replacement Lab
#     Brother Ball, CS345
# Author:
#     Lance Bunch
# Summary:
#     This lab showcases different algorithms
# Time:
#     Estimated: 11.0 Hrs
#		Actual: 	   0.0 Hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab10.o pr.o
	g++ -o a.out lab10.o pr.o
	tar -czf lab10.tar makefile *.cpp *.h

##############################################################
# The individual components
##############################################################
lab10.o: lab10.cpp pr.h
	g++ -c lab10.cpp

pr.o: pr*.h pr.cpp pr.h
	g++ -c pr.cpp


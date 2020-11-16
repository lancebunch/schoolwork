###############################################################
# Program:
#     Lab 11, Disk Scheduling Lab
#     Brother Ball, CS345
# Author:
#     Lance Bunch
# Summary:
#     This lab showcases and practices FCFS, C_LOOK, C_SCAN,
#		LOOK, and SCAN disk scheduling algorithms
# Time:
#     Estimated: 11.0 Hrs
#		Actual:     0.0 Hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab11.o ds.o
	g++ -o a.out lab11.o ds.o
	tar -czf lab11.tar makefile *.cpp *.h

##############################################################
# The individual components
##############################################################
lab11.o: lab11.cpp ds.h
	g++ -c lab11.cpp

ds.o: ds*.h ds.cpp ds.h
	g++ -c ds.cpp


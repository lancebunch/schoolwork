###############################################################
# Program:
#     Week 02, STACK
#     Brother Ercanbrack, CS235
# Author:
#     Lance Bunch
# Summary:
#     This Data Structure stacks data ontop of eachother and only
#		lets the user take things of the top of the stack. Error
#		handling informs the user if they are looking for data that
#		isn't there.
# Time:
#     6.5 Hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: stack.h week02.o infix.o 
	g++ -o a.out week02.o infix.o -std=c++11 
	tar -cf week02.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week02.o       : the driver program
#      infix.o        : the logic for the infix --> postfix program
##############################################################
week02.o: stack.h infix.h week02.cpp
	g++ -c week02.cpp -std=c++11

infix.o: stack.h infix.h infix.cpp
	g++ -c infix.cpp -std=c++11


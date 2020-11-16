###############################################################
# Program:
#     Week 06, NODE
#     Brother Ercanbrack, CS235
# Author:
#     Lance Bunch
# Summary:
#     Contains a Node class which is a pointer with data to build
#		the foundation of a linked-list
# Time:
#		7.0 Hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h week06.o 
	g++ -o a.out week06.o  -g -std=c++11
	tar -cf week06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week06.o      : the driver program
#      <anything else?>
##############################################################
week06.o: node.h week06.cpp sortInsertion.h
	g++ -c week06.cpp -g -std=c++11

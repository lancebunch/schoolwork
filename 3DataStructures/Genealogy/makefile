###############################################################
# Program:
#     Week 13, GENEALOGY
#     Brother Ercanbrack, CS235
# Author:
#     Lance Bunch
# Summary:
#     
# Time:
#     13.0 Hrs
###############################################################

##############################################################
# The main rule
##############################################################
a.out: bnode.h genealogy.o 
	g++ -o a.out genealogy.o  -std=c++11
	tar -cf genealogy.tar *.h *.cpp makefile

##############################################################
# The individual components
#      genealogy.o       : the driver program
##############################################################
genealogy.o: bnode.h list.h genealogy.cpp
	g++ -c genealogy.cpp -std=c++11

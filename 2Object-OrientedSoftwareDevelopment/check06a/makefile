###############################################################
# Program:
#     Checkpoint 06a, Makefiles
#     Brother Macbeth, CS165
# Author:
#     Lance Bunch
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


# Insert your rule for a.out here:
a.out : robot.o point.o check06a.o
	g++ robot.o point.o check06a.o
	tar -cf check06a.tar *.cpp *.h makefile

# Insert your rule for robot.o here:
robot.o : robot.cpp robot.h
	g++ -c robot.cpp

# Insert your rule for point.o here:
point.o : point.cpp point.h
	g++ -c point.cpp

# Insert your rule for check06a.o here:
check06a.0 : check06a.cpp
	g++ -c check06a.cpp

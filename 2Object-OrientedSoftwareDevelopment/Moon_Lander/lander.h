/*************************************************************
 * File: lander.h
 * Author: Lance Bunch
 *
 * Description: Contains the definition of the Lander class
 *************************************************************/
#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"


#include <iostream>

class Lander
{
private:
	Point point;
	int fuel;
	Velocity velocity;
	bool alive;
	bool landed; 

public:
	//default Constructor
	Lander();

	//Accessors with inline commands
	Point getPoint() const { return point; }
	Velocity getVelocity() const { return velocity; }
	bool isAlive() const { return alive; }
	bool isLanded() const { return landed; }
	int getFuel() const { return fuel; }

	bool canThrust();

	//Mutators
	void setLanded(bool landed);
	void setAlive(bool alive);
	void setFuel(int fuel);

	//Application Functions
	void applyGravity(float gravity);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();

	//Part of "The Game Loop"
	void advance();
	void draw();
};


#endif
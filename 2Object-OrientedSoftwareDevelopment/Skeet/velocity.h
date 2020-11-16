/*************************************************************
 * File: velocity.h
 * Author: Lance Bunch
 *
 * Description: Contains the definition of the Velocity class
 *************************************************************/
#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>

class Velocity
{
private:
	float Dx;
	float Dy;

public:
	//Default Constructor
	Velocity();
	//Non-Default Constuctor
	Velocity(float Dx, float Dy);

	//Accessors
	float getDx() const { return Dx; }
	float getDy() const { return Dy; }

	//Mutators
	void setDx(float Dx);
	void setDy(float Dy);
};


#endif
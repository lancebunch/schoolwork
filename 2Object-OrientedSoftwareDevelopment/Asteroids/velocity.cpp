/*************************************************************
 * File: velocity.cpp
 * Author: Lance Bunch
 *
 * Description: contains the constructors, accessors and mutators of
 *				the velocity class. Allowing input from the user.
 *************************************************************/
#include "velocity.h"

 /*****************************************************************************
 * Default Constructor
 * Purpose: Sets Dx and Dy to 0.
 *****************************************************************************/
Velocity::Velocity()
{
	setDx(0);
	setDy(0);
}

/*****************************************************************************
* Non-Default Constructor
* Purpose: sets Dx and Dy to whatever is inputed
*****************************************************************************/
Velocity::Velocity(float Dx, float Dy)
{
	setDx(Dx);
	setDy(Dy);
}

/*****************************************************************************
* Mutator: setDx
* Purpose: changes the class's Dx to whatever is inputed through "has-a
*		   relationships
*****************************************************************************/
void Velocity::setDx(float Dx)
{
	this->Dx = Dx;
}

/*****************************************************************************
* Mutator: setDy
* Purpose: Changes the class's Dy to whatever is inputed through "has-a
*		   relationships
*****************************************************************************/
void Velocity::setDy(float Dy)
{
	this->Dy = Dy;
}
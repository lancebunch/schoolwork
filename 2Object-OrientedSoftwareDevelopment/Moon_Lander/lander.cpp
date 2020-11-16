/*************************************************************
 * File: lander.cpp
 * Author: Lance Bunch
 *
 * Description: Conatains the lander with all of it's constructors
 *				accessors and mutators and lets you interact with
 *				the environment through it.
 *************************************************************/
#include "lander.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"


#include <iostream>
using namespace std;


/*****************************************************************************
* Default Constructor
* Purpose: sets all variable to their intended start position
*****************************************************************************/
Lander::Lander()
{
	setAlive(true);
	setFuel(500);
	setLanded(false);
	point.setX(10);
	point.setY(160);
	velocity.setDx(-1.0);
}

/*****************************************************************************
* Function: canThrust
* Purpose: checks to see if thrust should occur
*****************************************************************************/
bool Lander::canThrust()
{
	if (fuel > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*****************************************************************************
* Mutator: setLanded
* Purpose: Chagnes the state of landed if it occurs.
*****************************************************************************/
void Lander::setLanded(bool landed)
{
	this->landed = landed;
}

/*****************************************************************************
* Mutator: setAlive
* Purpose: changes the state of alive if it occurs.
*****************************************************************************/
void Lander::setAlive(bool alive)
{
	this->alive = alive;
}

/*****************************************************************************
* Mutator: setFuel
* Purpose: changes the state of fuel if it occurs.
*****************************************************************************/
void Lander::setFuel(int fuel)
{
	this->fuel = fuel;
}

/*****************************************************************************
* Function: applyGravity
* Purpose: continually applies gravity to the lander
*****************************************************************************/
void Lander::applyGravity(float gravity) 
{
	velocity.setDy(velocity.getDy() - gravity);
}

/*****************************************************************************
* Function: applyThrustLeft
* Purpose: applies flame aniamtion and adds to the velocity of x
*****************************************************************************/
void Lander::applyThrustLeft()
{
	if (fuel > 0)
	{
		velocity.setDx(velocity.getDx() + 0.1);
		fuel -= 1;
	}
}

/*****************************************************************************
* Function: applyThrustRight
* Purpose: applies flame animation and subtracts from the velocity of x
*****************************************************************************/
void Lander::applyThrustRight()
{
	if (fuel > 0)
	{
		velocity.setDx(velocity.getDx() - 0.1);
		fuel -= 1;
	}
}

/*****************************************************************************
* Function: applyThrustBottom
* Purpose: applies flame animation and adds to the velocity of y
*****************************************************************************/
void Lander::applyThrustBottom()
{
	if (fuel >= 3)
	{
		velocity.setDy(velocity.getDy() + 0.3);
		fuel -= 3;
	}
	else
	{
		setFuel(0);
	}
}

/*****************************************************************************
* Function: advance
* Purpose: advances the game forward and changes the location of the lander through that.
*****************************************************************************/
void Lander::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
}

/*****************************************************************************
* Function: draw
* Purpose: draws the lander at whatever point is given by the user.
*****************************************************************************/
void Lander::draw()
{
	drawLander(point);
}
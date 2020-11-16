/*************************************************************
 * File: bird.cpp
 * Author: Lance Bunch
 *
 * Description: Contains the extra code necessary for bird specific objects
 *************************************************************/

#include "bird.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

Bird::Bird()
{
}

/**************************************************************
* Non-Default Constructor
* Description: Manipulates the point class as inputed
***************************************************************/
Bird::Bird(Point &point) : FlyingObject(point)
{
	setPoint(point);
	velocity.setDx(4.0);

	//logic to determine the velocity of the bird dependent on location of spawn
	if (point.getY() >= 133)
	{
		velocity.setDy(-4.0);
	}
	else if (point.getY() >= 67 && point.getY() < 133)
	{
		velocity.setDy(-3.0);
	}
	else if (point.getY() >= 0 && point.getY() < 67)
	{
		velocity.setDy(-2.0);
	}
	else if (point.getY() >= -67 && point.getY() < 0)
	{
		velocity.setDy(2.0);
	}
	else if (point.getY() >= -133 && point.getY() < -67)
	{
		velocity.setDy(3.0);
	}
	else
		velocity.setDy(4.0);
}
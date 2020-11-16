/************************
 * File: flyingObject.cpp
 * Author: Lance Bunch
 *
 * Description: Contains the methods for the FlyingObject Class
 ******************************************************/
#include "flyingObject.h"
#include "point.h"
#include "velocity.h"


/*****************************************************
* Default Constructor
* Purpose: Sets Flying Objects' default settings
*****************************************************/
FlyingObject::FlyingObject()
{
	setAlive(true);
}

/*****************************************************
* Non - Default Constructor
* Purpose: Sets Flying Objects' settings to what is inputed
*****************************************************/
FlyingObject::FlyingObject(Point &point)
{
	setPoint(point);
	setAlive(alive);
}

/*****************************************************
* Method: advance
* Purpose: moves the Flying Object Forward
*****************************************************/
void FlyingObject::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
	if (point.getX() < -220)
	{
		point.setX(220);
	}
	else if (point.getX() > 220)
	{
		point.setX(-220);
	}
	else if (point.getY() < -220)
	{
		point.setY(220);
	}
	else if (point.getY() > 220)
	{
		point.setY(-220);
	}
}
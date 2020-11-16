/*************************************************************
 * File: flyingObject.cpp
 * Author: Lance Bunch
 *
 * Description: Defines a flying object base class
 *
 * Summary: The code containing the constructors and game loop funtions
 *			that help with advancement
 *************************************************************/

#include "flyingObject.h"
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"

/**************************************************************
* Default Constructor
* Description: Establishes default settings for member data
***************************************************************/
FlyingObject::FlyingObject()
{
	setAlive(true);
}

/**************************************************************
* Non-Default Constructor
* Description: Manipulates the point class as inputed
***************************************************************/
FlyingObject::FlyingObject(Point point)
{
	setPoint(point);
	setAlive(alive);
}

/**************************************************************
* Function: kill
* Description: Uses logic to eliminate a flying object
***************************************************************/
void FlyingObject::kill()
{
	setAlive(false);
}

/**************************************************************
* Function: advance
* Description: move the game forward one frame at a time.
***************************************************************/
void FlyingObject::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
}

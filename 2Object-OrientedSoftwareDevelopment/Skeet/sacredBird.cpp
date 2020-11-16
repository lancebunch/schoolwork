/*************************************************************
 * File: sacredBird.cpp
 * Author: Lance Bunch
 *
 * Description: Defines methods for the sacredBird class
 *************************************************************/

#include "flyingObject.h"
#include "bird.h"
#include "sacredBird.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

 /**************************************************************
 * Non-Default Constructor
 * Description: Manipulates the point class as inputed
 ***************************************************************/
SacredBird::SacredBird(Point &point) : Bird(point) //Initializes Constructor
{
}

/**************************************************************
* Method: draw
* Description: draws a sacred Bird on Screen
***************************************************************/
void SacredBird::draw() const
{
	if (isAlive())
	{
		drawSacredBird(point, 20);
	}
}

/**************************************************************
* Method: hit
* Description: detmerines whether or not the bird was hit
***************************************************************/
int SacredBird::hit()
{
	//if you kill this bird subtract 10 points
	kill();
	return -10;
}
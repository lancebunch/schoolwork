/*************************************************************
 * File: standardBird.cpp
 * Author: Lance Bunch
 *
 * Description: Defines methods for the standardBird class
 *************************************************************/

#include "flyingObject.h"
#include "bird.h"
#include "standardBird.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

 /**************************************************************
 * Non-Default Constructor
 * Description: Manipulates the point class as inputed
 ***************************************************************/
StandardBird::StandardBird(Point &point) : Bird(point) //Initializes Constructor
{
}

/**************************************************************
* Method: draw
* Description: draws a standard Bird on Screen
***************************************************************/
void StandardBird::draw() const
{
	if (isAlive())
	{
		drawCircle(point, 15);
	}
}

/**************************************************************
* Method: hit
* Description: detmerines whether or not the bird was hit
***************************************************************/
int StandardBird::hit()
{
	kill();
	return 1;
}
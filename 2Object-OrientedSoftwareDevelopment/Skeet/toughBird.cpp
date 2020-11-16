/*************************************************************
 * File: toughBird.cpp
 * Author: Lance Bunch
 *
 * Description: Defines methods for the toughBird class
 *************************************************************/

#include "flyingObject.h"
#include "bird.h"
#include "toughBird.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

 /**************************************************************
 * Non-Default Constructor
 * Description: Manipulates the point class as inputed
 ***************************************************************/
ToughBird::ToughBird(Point &point) : Bird(point) //initializes Constructor
{
	setNumHits(3);
	velocity.setDx(2.0);

	//logic to make the tough bird slower
	if (point.getY() >= 133)
	{
		velocity.setDy(-3.0);
	}
	else if (point.getY() >= 67 && point.getY() < 133)
	{
		velocity.setDy(-2.0);
	}
	else if (point.getY() >= 0 && point.getY() < 67)
	{
		velocity.setDy(-1.0);
	}
	else if (point.getY() >= -67 && point.getY() < 0)
	{
		velocity.setDy(1.0);
	}
	else if (point.getY() >= -133 && point.getY() < -67)
	{
		velocity.setDy(2.0);
	}
	else
		velocity.setDy(3.0);
}

/**************************************************************
* Method: draw
* Description: draws a tough Bird on Screen
***************************************************************/
void ToughBird::draw() const
{
	if (isAlive())
	{
		drawToughBird(point, 15, numHits);
	}
}

/**************************************************************
* Method: hit
* Description: detmerines whether or not the bird was hit
***************************************************************/
int ToughBird::hit()
{
	//logic to return points based off the amount of lives
	if (numHits == 3)
	{
		numHits--;
		return 1;
	}
	else if (numHits == 2)
	{
		numHits--;
		return 1;
	}
	else if (numHits == 1)
	{
		numHits--;
		kill();
		return 3;
	}
	else
	{
		kill();
		return 0;
	}
}
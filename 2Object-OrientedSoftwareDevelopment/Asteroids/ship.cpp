/*****************************************************
 * File: ship.cpp
 * Author: Lance Bunch
 *
 * Description: Containsa few of the specific methods to the
 *				ship class.
 ******************************************************/

#include "ship.h"
#include "flyingObject.h"
#include "point.h"
#include "uiDraw.h"

/*******************************************************
 * Default Constructor
 * Purpose: In place to call the flying object constructor
********************************************************/
Ship::Ship()
{
	setAngle(90);
	setExhaust(false);
}

/*******************************************************
 * Method: thrust
 * Purpose: Does trigonometry to give the user a way to move
 *			around the map.
  *****************************************************/
void Ship::thrust()
{
	velocity.setDx(velocity.getDx() + (THRUST_AMOUNT * (cos(M_PI / 180.0 * angle))));
	velocity.setDy(velocity.getDy() + (THRUST_AMOUNT * (sin(M_PI / 180.0 * angle))));

}

/*******************************************************
 * Method: rotateLeft
 * Purpose: Allows the player to rotate ship to the left
  *****************************************************/
void Ship::rotateLeft()
{
	angle += ROTATE_AMOUNT;
}

/*******************************************************
 * Method: rotateRight
 * Purpose: Allows the player to rotate ship to the right
  *****************************************************/
void Ship::rotateRight()
{
	angle -= ROTATE_AMOUNT;
}

/*******************************************************
 * Method: draw
 * Purpose: draws the ship on screen based on the rotate amount
 *			and the amount of thrust.
  *****************************************************/
void Ship::draw()
{
	drawShip(point, angle - 90, getExhaust());
}

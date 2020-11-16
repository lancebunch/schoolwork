/*****************************************************
 * File: bullet.cpp
 * Author: Lance Bunch
 *
 * Description: Containsa few of the specific methods to the 
 *				Bullet class.
 ******************************************************/

#include "bullet.h"
#include "flyingObject.h"
#include "uiDraw.h"

/*******************************************************
 * Default Constructor
 * Purpose: In place to call the flying object constructor
  *****************************************************/
Bullet::Bullet()
{
}

/*******************************************************
 * Method: draw
 * Purpose: draws the bullets on screen.
  *****************************************************/
void Bullet::draw()
{
	drawDot(point);
	life++;
	if (life == BULLET_LIFE)
	{
		kill();
	}
}

/*******************************************************
 * Method: fire
 * Purpose: Fires the bullets depending on ship point, angle,
 *			and Velocity.
  *****************************************************/
void Bullet::fire(const Point &point, const int angle, const Velocity &velocity)
{
	setPoint(point);
	this->velocity.setDx(velocity.getDx() + (BULLET_SPEED * (cos(M_PI / 180.0 * angle))));
	this->velocity.setDy(velocity.getDy() + (BULLET_SPEED * (sin(M_PI / 180.0 * angle))));
	
}
/*************************************************************
 * File: bullet.cpp
 * Author: Lance Bunch
 *
 * Description: Goes over the specific methods of the bullet class
 *************************************************************/
#include <cmath>
#define M_PI 3.1415826535897932

#include "bullet.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/**************************************************************
* Default Constructor
* Description: Establishes default settings for member data
***************************************************************/
Bullet::Bullet()
{
}

/**************************************************************
* Method: draw
* Description: draws the bullets on screen
***************************************************************/
void Bullet::draw() const
{
	drawDot(point);
}

/**************************************************************
* Method: fire
* Description: Determines user input and potentially fires a bullet
***************************************************************/
void Bullet::fire(Point point, float angle)
{
	//math given to us to help with bullet sendoff location
	float BULLET_SPEED = 10.0;
	setPoint(point);
	float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
	float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));
	velocity.setDx(dx);
	velocity.setDy(dy);
}
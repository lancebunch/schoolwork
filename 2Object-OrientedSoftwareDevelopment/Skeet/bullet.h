/*************************************************************
 * File: bullet.h
 * Author: Lance Bunch
 *
 * Description: Keeps track of bullets that are shot
 *
 * Summary: Adds a few extra specific functions ontop of the
 *			flying object class.
 *************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "flyingObject.h"
#include "point.h"

class Bullet : public FlyingObject
{
	public:
		//Constructor
		Bullet();

		//polymorphed function
		void draw() const;
		//bullet specific function
		void fire(Point point, float angle);
};
#endif
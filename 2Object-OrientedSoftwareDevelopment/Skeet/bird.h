/*************************************************************
 * File: brid.h
 * Author: Lance Bunch
 *
 * Description: Defines a derived bird class
 *
 * Summary: Adds a few extra specific functions ontop of the 
 *			flying object class.
 *************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include "flyingObject.h"
#include "point.h"

class Bird : public FlyingObject
{
	public:

		//Constructor
		Bird();
		Bird(Point &point);

		//game loop functions
		virtual void draw() const = 0;
		virtual int hit() = 0;
};


#endif

/*************************************************************
 * File: standardBird.h
 * Author: Lance Bunch
 *
 * Description: Defines a derived standardBird class
 *
 * Summary: Adds a few extra specific functions ontop of the
 *			bird class.
 *************************************************************/

#ifndef STANDARDBIRD_H
#define STANDARDBIRD_H

#include "bird.h"
#include "point.h"

class StandardBird : public Bird
{
	public:
		//Constructor
		StandardBird(Point &point);

		//Polymorphed Functions.
		void draw() const;
		int hit();
};

#endif
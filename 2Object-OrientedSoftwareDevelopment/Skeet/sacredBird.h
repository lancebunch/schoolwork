/*************************************************************
 * File: sacredBird.h
 * Author: Lance Bunch
 *
 * Description: Defines a derived sacredBird class
 *
 * Summary: Adds a few extra specific functions ontop of the
 *			bird class.
 *************************************************************/

#ifndef SACREDBIRD_H
#define SACREDBIRD_H

#include "bird.h"
#include "point.h"

class SacredBird : public Bird
{
public:
	//Mutator
	SacredBird(Point &point);

	//Polymorphed Functions
	void draw() const;
	int hit();
};

#endif
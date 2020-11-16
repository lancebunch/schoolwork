/*************************************************************
 * File: toughBird.h
 * Author: Lance Bunch
 *
 * Description: Defines a derived toughBird class
 *
 * Summary: Adds a few extra specific functions ontop of the
 *			bird class.
 *************************************************************/

#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

#include "bird.h"
#include "point.h"

class ToughBird : public Bird
{
	private:
		//necessary to give this more "lives"
		int numHits;
	public:
		//Constructor
		ToughBird(Point &point);

		//Mutator and accessor
		void setNumHits(int numHits) { this->numHits = numHits; }
		int getNumHits() const       { return numHits; }

		//Polymorphed functions
		void draw() const;
		int hit();
};

#endif

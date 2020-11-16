/*************************************************************
 * File: flyingObject.h
 * Author: Lance Bunch
 *
 * Description: Defines a flying object base class
 *
 * Summary: Establishes the member data, constructors, accessors
 *			and mutators for manipulation.
 *************************************************************/

#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "point.h"
#include "velocity.h"

class FlyingObject
{
	protected:
		Point point;
		Velocity velocity;
		bool alive;

	public:

		//constructors
		FlyingObject();
		FlyingObject(Point point);

		//accessors
		Point getPoint()       const { return point; }
		Velocity getVelocity() const { return velocity; }
		bool isAlive()         const { return alive; }

		//mutators
		void setPoint(Point point)          { this->point = point; }
		void setVelocity(Velocity velocity) { this->velocity = velocity; }
		void setAlive(bool alive)           { this->alive = alive; }

		//game loop logic
		void kill();
		void advance();
		virtual void draw() const = 0;
};

#endif
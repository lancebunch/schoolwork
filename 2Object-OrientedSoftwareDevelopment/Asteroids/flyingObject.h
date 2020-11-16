/*****************************************************
 * File: flyingObject.h
 * Author: Lance Bunch
 *
 * Description: Defines the Flying object class and includes the necessary
 *				member data and methods to prepare to be inherited
 ******************************************************/
#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"
#include <cmath>
#define M_PI 3.1415826535897932

// Put your FlyingObject class here
class FlyingObject
{
	protected:
		Point point;
		Velocity velocity;
		bool alive;

	public:
		//Constructors
		FlyingObject();
		FlyingObject(Point &point);

		//Accessors
		Point getPoint()       const { return point; }
		Velocity getVelocity() const { return velocity; }
		bool isAlive()         const { return alive; }

		//Mutators
		void setPoint   (const Point &point)          { this->point = point; }
		void setVelocity(const Velocity &velocity)    { this->velocity = velocity; }
		void setAlive   (const bool alive)            { this->alive = alive; }

		//Game Loop Functions
		void kill() { setAlive(false); }
		void advance();
		//Polymorphism. Derived classes will do more with this
		virtual void draw() = 0;
};



#endif /* flyingObject_h */

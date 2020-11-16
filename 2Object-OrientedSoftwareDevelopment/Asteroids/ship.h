/*****************************************************
 * File: ship.h
 * Author: Lance Bunch
 *
 * Description: Derives from the flying object class and
 *				declares its own private and public data
 ******************************************************/
#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObject.h"

// Put your Ship class here
class Ship : public FlyingObject
{
	private:
		int angle;
		bool exhaust;
	public:
		//Constructor
		Ship();

		//Accessor
		int getAngle()    const    { return angle; }
		bool getExhaust() const    { return exhaust; }

		//Mutator
		void setAngle  (const int angle)      { this->angle = angle; }
		void setExhaust(const bool exhaust)   { this->exhaust = exhaust; }
		
		//Ship specific methods
		void thrust();
		void rotateLeft();
		void rotateRight();

		//Game loop
		void draw();
};

#endif /* ship_h */

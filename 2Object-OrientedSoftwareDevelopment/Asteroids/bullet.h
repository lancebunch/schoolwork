/*****************************************************
 * File: bullet.h
 * Author: Lance Bunch
 *
 * Description: Derives from the flying object class.
 ******************************************************/
#ifndef bullet_h
#define bullet_h

#include "flyingObject.h"
#include "point.h"

#define BULLET_SPEED 5
#define BULLET_LIFE 40

// Put your Bullet class here
class Bullet : public FlyingObject
{
	private:
		int life = 0;
	public:
		//Constructor
		Bullet();

		//Bullet specific Methods
		void draw();
		void fire(const Point &point, const int angle, const Velocity &velocity);
};



#endif /* bullet_h */

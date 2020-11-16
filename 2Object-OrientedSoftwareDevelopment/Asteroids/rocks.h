/*****************************************************
 * File: rocks.h
 * Author: Lance Bunch
 *
 * Description: Derives from the flying object class and
 *				declares its own private and public data.
 *				Also contains the 3 rock size classes deriving
 *				from the rocks class.
 ******************************************************/
#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include "point.h"
#include "velocity.h"
#include <vector>


// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
	protected:
		int angle;
	public:
		//Constructor
		Rock(const Point &point);

		//Accessor
		int getAngle() const { return angle; }

		//Mutator
		void setAngle(const int angle) { this->angle = angle; }

		//Polymorphed draw Function
		virtual void draw() = 0;
		virtual std::vector<Rock*> hit() = 0;
};


//   BigRock
class BigRock : public Rock
{
	public:
		BigRock(const Point &point);

		void draw();
		std::vector<Rock*> hit();
};

//   MediumRock
class MediumRock : public Rock
{
	public:
		MediumRock(const Point &point, const Velocity &velocity);

		void draw();
		std::vector<Rock*> hit();
};

//   SmallRock
class SmallRock : public Rock
{
	public:
		SmallRock(const Point &point, const Velocity &velocity);

		void draw();
		std::vector<Rock*> hit();
};



#endif /* rocks_h */

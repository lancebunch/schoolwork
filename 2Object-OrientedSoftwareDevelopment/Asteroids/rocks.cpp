/*****************************************************
 * File: rocks.cpp
 * Author: Lance Bunch
 *
 * Description: Contains a few of the specific methods to the
 *				different rock classes.
 ******************************************************/

#include "rocks.h"
#include "uiDraw.h"

															//Rocks Methods
 /*******************************************************
  * Non-Default Constructor
  * Purpose: Sets the point of each rock when it is created
   *****************************************************/
Rock::Rock(const Point &point)
{
	setPoint(point);
}

															//BigRock Methods
/*******************************************************
 * Non-Default Constructor
 * Purpose: Calls Non-Default Contructor for Rock
  *****************************************************/
BigRock::BigRock(const Point &point) : Rock(point)
{
	velocity.setDx(1.5 * sin(random(1, 360)));
	velocity.setDy(1.5 * cos(random(1, 360)));
}

/*******************************************************
 * Method: draw
 * Purpose: Draws a big rock on screen
  *****************************************************/
void BigRock::draw() 
{
	angle += BIG_ROCK_SPIN;
	drawLargeAsteroid(point, angle);
}

/*******************************************************
 * Method: hit
 * Purpose: handles what to do when a big rock is hit
  *****************************************************/
std::vector<Rock*> BigRock::hit()
{
	std::vector<Rock*> rocks;
	rocks.push_back(new MediumRock(getPoint(), getVelocity()));
	rocks.push_back(new MediumRock(getPoint(), getVelocity()));
	rocks.push_back(new SmallRock(getPoint(), getVelocity()));
	kill();
	return rocks;
}

															//MediumRock Methods
/*******************************************************
 * Non-Default Constructor
 * Purpose: Calls Non-Default Contructor for Rock
  *****************************************************/
MediumRock::MediumRock(const Point &point, const Velocity &velocity) : Rock(point)
{
	setVelocity(velocity);
	this->velocity.setDx(this->velocity.getDx() + random(0.5, 2.0));
	this->velocity.setDy(this->velocity.getDy() - random(0.5, 2.0));
}

/*******************************************************
 * Method: draw
 * Purpose: Draws a medium rock on screen based off death of
 *			a Big Rock
  *****************************************************/
void MediumRock::draw()
{
	angle += MEDIUM_ROCK_SPIN;
	drawMediumAsteroid(point, angle);
}

/*******************************************************
 * Method: hit
 * Purpose: handles what to do when a Medium rock is hit
  *****************************************************/
std::vector<Rock*> MediumRock::hit()
{
	std::vector<Rock*> rocks;
	rocks.push_back(new SmallRock(getPoint(), getVelocity()));
	rocks.push_back(new SmallRock(getPoint(), getVelocity()));
	kill();
	return rocks;
}

															//SmallRock Methods
/*******************************************************
 * Non-Default Constructor
 * Purpose: Calls Non-Default Contructor for Rock
  *****************************************************/
SmallRock::SmallRock(const Point &point, const Velocity &velocity) : Rock(point)
{
	setVelocity(velocity);
	this->velocity.setDx(this->velocity.getDx() - random(1.0, 2.0));
	this->velocity.setDy(this->velocity.getDy() + random(1.0, 2.0));
}

/*******************************************************
 * Method: draw
 * Purpose: Draws a small rock on screen based off death of
 *			a Big Rock or medium rock.
  *****************************************************/
void SmallRock::draw()
{
	angle += SMALL_ROCK_SPIN;
	drawSmallAsteroid(point, angle);
}

/*******************************************************
 * Method: hit
 * Purpose: handles what to do when a small rock is hit
  *****************************************************/
std::vector<Rock*> SmallRock::hit()
{
	std::vector<Rock*> rocks;
	kill();
	return rocks;
}
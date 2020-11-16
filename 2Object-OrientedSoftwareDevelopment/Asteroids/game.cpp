/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include "ship.h"
using namespace std;


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}


/***************************************
 * Game Constructor
 ***************************************/
Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
	Point p1;
	p1.setX(random(-200, -20));
	p1.setY(random(20, 200));

	Point p2;
	p2.setX(random(-200, -20));
	p2.setY(random(-200, 20));

	Point p3;
	p3.setX(random(20, 200));
	p3.setY(random(-200, -20));

	Point p4;
	p4.setX(random(50, 200));
	p4.setY(random(20, 200));

	Point p5;
	p5.setX(random(-200, 200));
	p5.setY(random(-200, 200));

	rocks.push_back(new BigRock(p1));
	rocks.push_back(new BigRock(p2));
	rocks.push_back(new BigRock(p3));
	rocks.push_back(new BigRock(p4));
	rocks.push_back(new BigRock(p5));
}


/***************************************
 * Game Advance
 * Description: Advance the game one unit of time
 ***************************************/
void Game::advance()
{
	advanceShip();
	advanceBullets();
	advanceRocks();

	handleCollisions();
	cleanUpZombies();
}

/***************************************
 * Game advanceShip
 * Description: Advance the ship one unit of time
 ***************************************/
void Game::advanceShip()
{
	if (ship.isAlive())
	{
		ship.advance();
	}
}

/***************************************
 * Game advanceBullets
 * Description: Advance the Bullets one unit of time
 ***************************************/
void Game::advanceBullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].advance();
		}
	}
}

/***************************************
 * Game advanceRocks
 * Description: Advance the Rocks one unit of time
 ***************************************/
void Game::advanceRocks()
{
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i]->isAlive())
		{
			rocks[i]->advance();
		}
	}
}


/**************************************************************************
 * Game handleCollisions
 * Description: Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game::handleCollisions()
{
	for (int h = 0; h < rocks.size(); h++)
	{
		if (rocks[h] != NULL && rocks[h]->isAlive())
		{
			// this bullet is alive, see if its too close
			for (int i = 0; i < bullets.size(); i++)
			{
				if (bullets[i].isAlive())
				{
					// BTW, this logic could be more sophisiticated, but this will
					// get the job done for now...
					if (getClosestDistance(bullets[i], *rocks[h]) < CLOSE_ENOUGH)
					{
						//we have a hit!
						//int points = rocks[i].hit();
						//score += points;
						std::vector<Rock*>death = rocks[h]->hit();
						rocks.insert(rocks.end(), death.begin(), death.end());


						// the bullet is dead as well
						bullets[i].kill();
					} 
					
				} // if bullet is alive

			} // for bullet count

			if (ship.isAlive())
			{
				if (getClosestDistance(*rocks[h], ship) < CLOSE_ENOUGH)
				{
					ship.kill();
					std::vector<Rock*>death = rocks[h]->hit();
				} // for Closest Distance

			} // if ship is alive

		} // if Rock is alive

	} // for Rocks
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, )
 **************************************************************************/
void Game::cleanUpZombies()
{
	vector<Bullet>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet bullet = *bulletIt;

		if (!bullet.isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...


			// remove from list and advance
			bulletIt = bullets.erase(bulletIt);
		}
		else
		{
			bulletIt++; // advance
		}
	}

	vector<Rock*>::iterator rockIt = rocks.begin();
	while (rockIt != rocks.end())
	{
		Rock* pRock = *rockIt;
		// Asteroids Hint:
		// If we had a list of pointers, we would need this line instead:
		//Bullet* pBullet = *bulletIt;
		if (!pRock->isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...
			delete pRock;

			// remove from list and advance
			rockIt = rocks.erase(rockIt);
		}
		else
		{
			rockIt++; // advance
		}
	}
}

/***************************************
 * Game handleInput
 * Description: Accepts input from the user
 ***************************************/
void Game::handleInput(const Interface & ui)
{
	if (ship.isAlive())
	{
		ship.setExhaust(false);
		if (ui.isLeft())
		{
			ship.rotateLeft();
		}

		if (ui.isRight())
		{
			ship.rotateRight();
		}

		if (ui.isUp())
		{
			ship.thrust();
			ship.setExhaust(true);
		}

		if (ui.isSpace())
		{
			Bullet newBullet;
			newBullet.fire(ship.getPoint(), ship.getAngle(), ship.getVelocity());

			bullets.push_back(newBullet);
		}
	}
}

/*********************************************
 * Game Draw
 * Description: Draw everything on the screen
 *********************************************/
void Game::draw(const Interface & ui)
{
	
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks[i]->isAlive())
		{
			rocks[i]->draw();
		}
	}

	for (int h = 0; h < bullets.size(); h++)
	{
		if (bullets[h].isAlive() && ship.isAlive())
		{
			bullets[h].draw();

		}
	}

	if (ship.isAlive())
	{
		ship.draw();
	}
}

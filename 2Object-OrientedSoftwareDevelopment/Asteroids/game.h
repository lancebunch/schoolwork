/*************************************************************
 * File: game.h
 * Author: Br. Burton, Modified by Lance Bunch
 *
 * Description: The game of Asteroids. This class holds each piece
 *  of the game (rocks, ship, bullets). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "bullet.h"
#include "ship.h"
#include "rocks.h"
#define CLOSE_ENOUGH 15

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
	/*********************************************
	 * Constructor
	 * Initializes the game
	 *********************************************/
	Game(Point tl, Point br);
	

	float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;

	/*********************************************
	 * Function: handleInput
	 * Description: Takes actions according to whatever
	 *  keys the user has pressed.
	 *********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	 * Function: advance
	 * Description: Move everything forward one
	 *  step in time.
	 *********************************************/
	void advance();

	/*********************************************
	 * Function: draw
	 * Description: draws everything for the game.
	 *********************************************/
	void draw(const Interface & ui);

private:
	// The coordinates of the screen
	Point topLeft;
	Point bottomRight;

	//int score;

	Ship ship;
	std::vector<Bullet> bullets;
	std::vector<Rock*> rocks;


	/*************************************************
	 * Private methods to help with the game logic.
	 *************************************************/
	void advanceBullets();
	void advanceShip();
	void advanceRocks();

	void handleCollisions();
	void cleanUpZombies();
};

#endif /* GAME_H */

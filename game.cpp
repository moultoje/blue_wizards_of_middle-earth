/*******************************************************************************
** Program Name: game.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: The implementation file for the game class. Defines the
**				constructor, desctructor, and the top-level function for the
**				game.
*******************************************************************************/

#include "game.hpp"
#include "wizard.hpp"
#include "space.hpp"
#include "startingRoom.hpp"
#include "mainRoom.hpp"
#include "swordRoom.hpp"
#include "hatRoom.hpp"
#include "pathRoom.hpp"
#include "romestamoRoom.hpp"
#include "clearScreen.hpp"

#include <iostream>

/*******************************************************************************
** game default constructor:
**		Default constructor for the game. Dynamically allocates the room objects
**		and the wizard object.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
Game::Game()
{
	// Dynamically allocate all the necessary objects.
	Morinehtar = new Wizard;
	startingR = new StartingRoom(Morinehtar);
	mainR = new MainRoom(Morinehtar);
	swordR = new SwordRoom(Morinehtar);
	hatR = new HatRoom(Morinehtar);
	pathR = new PathRoom(Morinehtar);
	RomestamoR = new RomestamoRoom(Morinehtar);

	// Link the rooms together.
	startingR->setTop(mainR);
	mainR->setTop(pathR);
	mainR->setRight(hatR);
	mainR->setBottom(startingR);
	mainR->setLeft(swordR);
	swordR->setRight(mainR);
	hatR->setLeft(mainR);
	pathR->setTop(RomestamoR);
	pathR->setBottom(mainR);
	RomestamoR->setBottom(pathR);

	// Set the current room to the starting room.
	currentR = startingR;
}

/*******************************************************************************
** game destructor:
**		Destructor for the game.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
Game::~Game()
{
	// Destroy the dynamically allocated objects.
	delete Morinehtar;
	delete startingR;
	delete mainR;
	delete swordR;
	delete hatR;
	delete pathR;
	delete RomestamoR;

	// Set all pointers to NULL.
	Morinehtar = NULL;
	startingR = NULL;
	mainR = NULL;
	swordR = NULL;
	hatR = NULL;
	pathR = NULL;
	RomestamoR = NULL;
	currentR = NULL;
}

/*******************************************************************************
** play:
**		Executes the top level execution for the game. Checks for when the user
**		runs out of health or finds their friend.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
void Game::play()
{
	// While loop for the player being alive.
	do
	{
		// Print the map and move the room's characters.
		currentR->printLayout();
		currentR = currentR->move(currentR);

		if(Morinehtar->getCurHealth() == 0)
		{
			clearScreen();
			std::cout << "You have failed to find Romestamo before "
					  << "your health ran out."
					  << "\n\n"
					  << "Better luck next time."
					  << std::endl;
		}
		else if(currentR == RomestamoR)
		{
			clearScreen();

			std::cout << "Congratulations, you have found "
				  << "Romestamo!"
				  << "\n\n"
				  << "Thank you for playing."
				  << std::endl;

			Morinehtar->setHealth(0);
		}
	}while(Morinehtar->getCurHealth() > 0);

	return;
}

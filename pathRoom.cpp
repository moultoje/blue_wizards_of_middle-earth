/*******************************************************************************
** Program Name: pathRoom.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Implementation file for Path Room class. Defines the constructor
**				and the printLayout function of the class.
*******************************************************************************/

#include "pathRoom.hpp"
#include "space.hpp"
#include "wizard.hpp"
#include "validate.hpp"
#include "clearScreen.hpp"

#include <iostream>

/*******************************************************************************
** PathRoom default constructor:
**		Default constructor for the pathRoom. Sets the layout of the room.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
PathRoom::PathRoom(Wizard *wizInput) : Space(wizInput)
{
	// Set the walls of the room.
	for(int i = 0; i < 49; i++)
	{
		layout[0][i] = 'E';
		layout[26][i] = 'E';
	}
	for(int i = 0; i < 27; i++)
	{
		layout[i][0] = 'E';
		layout[i][48] = 'E';
	}

	// Set the doors of the room.
	layout[1][23] = 'E';
	layout[1][25] = 'E';
	layout[25][23] = 'E';
	layout[25][25] = 'E';

	// Lock the door in the room.
	layout[1][24] = 'L';

	// Set the Wizard.
	layout[24][24] = 'W';
}

/*******************************************************************************
** printLayout:
**		Prints a message about the current room, the items and user health,
**		the layout of the room, and the potential actions for the user.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
void PathRoom::printLayout()
{
	// Unlock the door in the path room if the user has all of the items
	this->unlockDoor();

	clearScreen();

	// Prints the header for this room.
	std::cout << "Welcome to the path room.";
	std::cout << "\nIf you have collected all of your items, you may continue "
	          << "forward to Romestamo.";
	std::cout << "\nIf you have not collected all of your items, please go "
	          << "back and search for the remaining items.";

	// Prints what items the user has.
	std::cout << "\n\nItems: ";
	for(int i = 0; i < 3; i++)
	{
		std::cout << Morinehtar->getItems(i) << " ";
	}

	//Prints the health the user has.
	std::cout << "\n\nHealth: "
	          << Morinehtar->getCurHealth()
	          << "/"
	          << Morinehtar->getTotHealth();

	std::cout << "\n\n";

	// Prints the map.
	for(int i = 0; i < 27; i++)
	{
		for(int j = 0; j < 49; j++)
		{
			std::cout << layout[i][j];
		}
		std::cout << std::endl;
	}

	// Prints actions.
	std::cout << "\n\nAvaliable Actions: 1 - Up, 2 - Right, 3 - Down, 4 - "
		  << "Left, 5 - Pick Up Object\n\n";

	std::cout << "Please enter your action: ";

	return;
}

/*******************************************************************************
** unlockDoor:
**		Checks to see if the door should be unlocked in the pathRoom.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
void PathRoom::unlockDoor()
{
	// Number of items.
	int numItems = 0;

	// If the wizard has all three items, then unlock door.
	for(int i = 0; i < 3; i++)
	{
		if(Morinehtar->getItems(i) != "")
		{
			numItems += 1;
		}
	}

	// If all three are there, then remove lock.
	if(numItems == 3)
	{
		layout[1][24] = ' ';
	}

	return;
}
/*******************************************************************************
** Program Name: startingRoom.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Implementation file for Starting Room class. Defines the 
**				constructor and the printLayout function of the class.
*******************************************************************************/

#include "startingRoom.hpp"
#include "space.hpp"
#include "wizard.hpp"
#include "validate.hpp"
#include "clearScreen.hpp"

#include <iostream>

/*******************************************************************************
** StartingRoom default constructor:
**		Default constructor for the startingRoom. Sets the layout of the room.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
StartingRoom::StartingRoom(Wizard *wizInput) : Space(wizInput)
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

	// Lock the door in the room.
	layout[1][24] = 'L';

	// Set the Wizard.
	layout[20][10] = 'W';
	Morinehtar->setRowNew(20);
	Morinehtar->setColNew(10);

	// Set the staff.
	layout[10][20] = 'S';
}

/*******************************************************************************
** printLayout:
**		Prints a message about the current room, the items and user health,
**		the layout of the room, and the potential actions for the user.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
void StartingRoom::printLayout()
{
	clearScreen();

	// Prints the header for this room.
	std::cout << "Welcome to the first room.";
	std::cout << "\nFeel free to get used to the controls of the game, but "
	          << "be careful of using too much of your health!";
	std::cout << "\nWhen you are ready, pick up your staff (S) and "
	          << "proceed to the door at the top of the screen.";

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
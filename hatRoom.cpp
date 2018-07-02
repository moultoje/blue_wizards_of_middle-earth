/*******************************************************************************
** Program Name: hatRoom.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Implementation file for Hat Room class. Defines the constructor
**				and the printLayout function of the class.
*******************************************************************************/

#include "hatRoom.hpp"
#include "space.hpp"
#include "wizard.hpp"
#include "validate.hpp"
#include "clearScreen.hpp"

#include <iostream>

/*******************************************************************************
** HatRoom default constructor:
**		Default constructor for the hatRoom. Sets the layout of the room.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
HatRoom::HatRoom(Wizard *wizInput) : Space(wizInput)
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
	layout[13][1] = 'E';
	layout[15][1] = 'E';

	// Set the Wizard.
	layout[14][2] = 'W';

	// Set the hat.
	layout[4][43] = 'H';
}

/*******************************************************************************
** printLayout:
**		Prints a message about the current room, the items and user health,
**		the layout of the room, and the potential actions for the user.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
void HatRoom::printLayout()
{
	clearScreen();

	// Prints the header for this room.
	std::cout << "Welcome to the hat room.";
	std::cout << "\nYour hat that fell off of your head is in the corner.";
	std::cout << "\nYou'll need to grab your hat before you can meet back "
	          << "up with Romestamo.";

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
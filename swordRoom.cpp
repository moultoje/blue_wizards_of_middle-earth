/*******************************************************************************
** Program Name: swordRoom.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Implementation file for Sword Room class. Defines the
**				constructor and the printLayout function of the class.
*******************************************************************************/

#include "swordRoom.hpp"
#include "space.hpp"
#include "wizard.hpp"
#include "validate.hpp"
#include "clearScreen.hpp"

#include <iostream>

/*******************************************************************************
** SwordRoom default constructor:
**		Default constructor for the swordRoom. Sets the layout of the room.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
SwordRoom::SwordRoom(Wizard *wizInput) : Space(wizInput)
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
	layout[13][47] = 'E';
	layout[15][47] = 'E';

	// Set the Wizard.
	layout[14][46] = 'W';

	// Set the sword.
	layout[20][4] = 'S';
}

/*******************************************************************************
** printLayout:
**		Prints a message about the current room, the items and user health,
**		the layout of the room, and the potential actions for the user.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
void SwordRoom::printLayout()
{
	clearScreen();

	// Prints the header for this room.
	std::cout << "Welcome to the sword room.";
	std::cout << "\nYour sword that fell is in the corner.";
	std::cout << "\nYou'll need to grab your sword before you can meet back "
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
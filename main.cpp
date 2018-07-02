/*******************************************************************************
** Program Name: finalProject.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: The main function for the Blue Wizards of Middle-earth game. 
**				It prints a welcome message, creates a game object, and starts
**				the game.
*******************************************************************************/

#include "clearScreen.hpp"
#include "validate.hpp"
#include "game.hpp"

#include <iostream>

int main()
{
	// Clear the screen.
	clearScreen();

	//Print the welcome message.
	std::cout << "     Welcome to the mountain range of Ocacarni."
		  << "\n\n"
		  << "You are Morinehtar, a Blue Wizard from the Lord of the"
		  << "\nRings Universe. You were travelling east of"
		  << "\nMiddle-earth with your companion, Romestamo, for the"
		  << "\npurpose of weakening Sauron's forces in that area."
		  << "\nWhile travelling through the Ocacarni mountains,"
		  << "\nRomestamo and you fall from a ledge and are"
		  << "\nseperated in the depths of the mountains."
		  << "\n\nYour goal is to collect your fallen items and find"
		  << "\nRomestamo."
		  << "\n\nBe careful - each move you make takes away from your"
		  << "\nhealth!"
		  << "\n\nGood luck traveller."
		  << "\nEnter any number to begin your quest."
		  << std::endl;
	validateInt();

	// Create the game object.
	Game gameobj;

	// Play the game.
	gameobj.play();

	return 0;
}

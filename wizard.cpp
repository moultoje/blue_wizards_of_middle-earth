/*******************************************************************************
** Program Name: wizard.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Implementation file for the wizard class. Defines the
**				constructor, destructor, getters, setters, a move function, and
**				a function to increment the wizard's health. 
*******************************************************************************/

#include "wizard.hpp"

#include <vector>
#include <string>

/*******************************************************************************
** Wizard
**		Constructor for the Wizard class. Sets the current and total health to
**		400 and creates the item vector with a length of 3.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
Wizard::Wizard()
{
	totHealth = 400;
	curHealth = totHealth;
	for(int i = 0; i < 3; i++)
	{
		items.push_back("");
	}
}

/*******************************************************************************
** ~Wizard
**		Destructor for the Wizard class.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
Wizard::~Wizard()
{
}

/*******************************************************************************
** move
**		Moves the wizard depending on the user's input. If the space that the
**		user is trying to move to is occupied, then don't move the wizard.
** Arguments:
**		int input - the input from the user
**		char **layout - the current map of the room
** Returns: N/A
*******************************************************************************/
void Wizard::move(int input, char **layout)
{
	colOld = colNew;
	rowOld = rowNew;

	if(input == 1 && layout[rowNew - 1][colNew] == ' ')
	{
		rowNew -= 1;
	}
	else if(input == 2 && layout[rowNew][colNew + 1] == ' ')
	{
		colNew += 1;
	}
	else if(input == 3 && layout[rowNew + 1][colNew] == ' ')
	{
		rowNew += 1;
	}
	else if(input == 4 && layout[rowNew][colNew - 1] == ' ')
	{
		colNew -= 1;
	}

	return;
}

/*******************************************************************************
** incrementHealth
**		Increments the Wizard's health.
** Arguments:
**		int input - the value to increment the wizard's health by.
** Returns: N/A
*******************************************************************************/
void Wizard::incrementHealth(int input)
{
	curHealth += input;

	return;
}

/*******************************************************************************
** setHealth
**		Sets the Wizard's health.
** Arguments:
**		int input - the value to set the wizard's health to.
** Returns: N/A
*******************************************************************************/
void Wizard::setHealth(int input)
{
	curHealth = input;

	return;
}

/*******************************************************************************
** getCurHealth
**		Returns the health of the wizard.
** Arguments: N/A
** Returns:
**		curHealth - the current health value of the wizard
*******************************************************************************/
int Wizard::getCurHealth()
{
	return curHealth;
}

/*******************************************************************************
** getTotHealth
**		Returns the maximum health possible of the wizard.
** Arguments: N/A
** Returns:
**		totHealth - the maximum health value possible of the wizard
*******************************************************************************/
int Wizard::getTotHealth()
{
	return totHealth;
}

/*******************************************************************************
** addToItems
**		Adds an item found to the item vector.
** Arguments:
**		std::string input - item to be added to the vector
** Returns: N/A
*******************************************************************************/
void Wizard::addToItems(std::string input)
{
	// Create bool for if the item was added earlier in the vector.
	bool wasAdded = 0;

	for(int i = 0; i < 3; i++)
	{
		if(items[i] == "" && !wasAdded)
		{
			items[i] = input;
			wasAdded = 1;
		}
	}

	return;
}

/*******************************************************************************
** getItems
**		Returns an item in the vector.
** Arguments:
**		int input - index of the item vector to check contents
** Returns:
**		items[input] - returns the name of the item
*******************************************************************************/
std::string Wizard::getItems(int input)
{
	return items[input];
}

/*******************************************************************************
** setColNew
**		Sets the new column position.
** Arguments:
**		int input - the value to set the column position to.
** Returns: N/A
*******************************************************************************/
void Wizard::setColNew(int input)
{
	colNew = input;

	return;
}

/*******************************************************************************
** getColNew
**		Returns the new column position.
** Arguments: N/A
** Returns: 
**		colNew - the new column position
*******************************************************************************/
int Wizard::getColNew()
{
	return colNew;
}

/*******************************************************************************
** getColOld
**		Returns the old column position.
** Arguments: N/A
** Returns: 
**		colOld - the old column position
*******************************************************************************/
int Wizard::getColOld()
{
	return colOld;
}

/*******************************************************************************
** setRowNew
**		Sets the row column position.
** Arguments:
**		int input - the value to set the row position to.
** Returns: N/A
*******************************************************************************/
void Wizard::setRowNew(int input)
{
	rowNew = input;

	return;
}

/*******************************************************************************
** getRowNew
**		Returns the new row position.
** Arguments: N/A
** Returns: 
**		rowNew - the new row position
*******************************************************************************/
int Wizard::getRowNew()
{
	return rowNew;
}

/*******************************************************************************
** getRowOld
**		Returns the old row position.
** Arguments: N/A
** Returns: 
**		rowOld - the old row position
*******************************************************************************/
int Wizard::getRowOld()
{
	return rowOld;
}

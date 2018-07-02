/*******************************************************************************
** Program Name: space.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Implementaion file for Space class. Defines the constructor,
**				destructor, get functions, set functions, and the move function.
*******************************************************************************/

#include "space.hpp"
#include "wizard.hpp"
#include "validate.hpp"

#include <iostream>

/*******************************************************************************
** Space default constructor:
**		Default constructor for the space class. Sets the Wizard pointer to the
**		game's wizard, dynamically creates a 2d array for the map, the space 
**		pointers to null, and fill the map with blank characters.
** Arguments:
**		Wizard *wizInput - the pointer to the game's wizard
** Returns: N/A
*******************************************************************************/
Space::Space(Wizard *wizInput)
{
	// Set the Space's wizard to the input.
	Morinehtar = wizInput;

	// Allocate dynamic memory for the layout.
	layout = new char * [27];

	for(int i = 0; i < 27; i++)
	{
		layout[i] = new char[49];
	}

	// Set pointers to NULL
	top = NULL;
	right = NULL;
	bottom = NULL;
	left = NULL;

	// Set the layout to blank characters.
	for(int i = 0; i < 27; i++)
	{
		for(int j = 0; j < 49; j++)
		{
			layout[i][j] = ' ';
		}
	}
}

/*******************************************************************************
** Space destructor:
**		Destructor for the space class. Deletes the dynamically created map.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
Space::~Space()
{
	// Delete dynamic memory.
	for(int i = 0; i < 27; i++)
	{
		delete [] layout[i];
	}
	delete [] layout;
}

/*******************************************************************************
** setTop
**		Sets the top pointer to the room that is above and connected to the
**		current room.
**	Arguments: 
**		Space *input - room that is above the current room
**	Returns: N/A
*******************************************************************************/
void Space::setTop(Space *input)
{
	top = input;

	return;
}

/*******************************************************************************
** getTop
**		Gets the top pointer to the room that is above and connected to the 
**		current room.
**	Arguments: N/A
**	Returns: 
**		top - pointer to the room that is above of the current room
*******************************************************************************/
Space * Space::getTop()
{
	return top;
}

/*******************************************************************************
** setRight
**		Sets the right pointer to the room that is to the right of and 
**		connected to the current room.
**	Arguments: 
**		Space *input - room that is to the right of the current room
**	Returns: N/A
*******************************************************************************/
void Space::setRight(Space *input)
{
	right = input;

	return;
}

/*******************************************************************************
** getRight
**		Gets the right pointer to the room that is to the right of and 
**		connected to the current room.
**	Arguments: N/A
**	Returns: 
**		right - pointer to the room that is right of the current room
*******************************************************************************/
Space * Space::getRight()
{
	return right;
}

/*******************************************************************************
** setBottom
**		Sets the bottom pointer to the room that is below and connected to the
**		current room.
**	Arguments: 
**		Space *input - room that is below the current room
**	Returns: N/A
*******************************************************************************/
void Space::setBottom(Space *input)
{
	bottom = input;

	return;
}

/*******************************************************************************
** getBottom
**		Gets the bottom pointer to the room that is below and connected to the 
**		current room.
**	Arguments: N/A
**	Returns: 
**		bottom - pointer to the room that is below of the current room
*******************************************************************************/
Space * Space::getBottom()
{
	return bottom;
}

/*******************************************************************************
** setLeft
**		Sets the left pointer to the room that is to the left of and 
**		connected to the current room.
**	Arguments: 
**		Space *input - room that is to the left of the current room
**	Returns: N/A
*******************************************************************************/
void Space::setLeft(Space *input)
{
	left = input;

	return;
}

/*******************************************************************************
** getLeft
**		Gets the left pointer to the room that is to the left of and 
**		connected to the current room.
**	Arguments: N/A
**	Returns: 
**		left - pointer to the room that is left of the current room
*******************************************************************************/
Space * Space::getLeft()
{
	return left;
}

/*******************************************************************************
** move:
**		Moves the characters that are in the current room.
** Arguments:
**		Space *room - the current room that the user is in
** Returns: 
**		room - the room that the user is in after making the move
*******************************************************************************/
Space * Space::move(Space *room)
{
	// Get and validate the user's input to move.
	int wizMove;
	validateAction(&wizMove);

	// If the input is either 1, 2, 3, or 4, then move the wizard.
	if(wizMove > 0 && wizMove < 5)
	{
		Morinehtar->move(wizMove, layout);

		// If the wizard moves to a doorway, change the current room to the
		// room that the wizard moved to.
		if(Morinehtar->getRowNew() == 1 && Morinehtar->getColNew() == 24
			&& room->getTop() != NULL)
		{
			Morinehtar->setRowNew(24);
			Morinehtar->setColNew(24);
			return room->getTop();
		}
		else if(Morinehtar->getRowNew() == 14 && Morinehtar->getColNew() == 47
			&& room->getRight() != NULL)
		{
			Morinehtar->setRowNew(14);
			Morinehtar->setColNew(2);
			return room->getRight();
		}
		else if(Morinehtar->getRowNew() == 25 && Morinehtar->getColNew() == 24
			&& room->getBottom() != NULL)
		{
			Morinehtar->setRowNew(2);
			Morinehtar->setColNew(24);
			return room->getBottom();
		}
		else if(Morinehtar->getRowNew() == 14 && Morinehtar->getColNew() == 1
			&& room->getLeft() != NULL)
		{
			Morinehtar->setRowNew(14);
			Morinehtar->setColNew(46);
			return room->getLeft();
		}
	}

	

	// If the input is 5, then check to see if an item can be added to
	// inventory. If it can, add to the inventory and remove indication
	// from map.
	if(wizMove == 5)
	{
		int minRow = Morinehtar->getRowNew() - 1;
		int maxRow = Morinehtar->getRowNew() + 1;
		int minCol = Morinehtar->getColNew() - 1;
		int maxCol = Morinehtar->getColNew() + 1;
		for(int i = minRow; i <= maxRow; i++)
		{
			for(int j = minCol; j <= maxCol; j++)
			{
				if(layout[i][j] == 'S')
				{
					if(room->getTop() != NULL){
						Morinehtar->addToItems("Staff");
						layout[i][j] = ' ';
						layout[1][24] = ' ';
					} else{
						Morinehtar->addToItems("Sword");
						layout[i][j] = ' ';
					}
					
				}
				else if(layout[i][j] == 'H')
				{
					Morinehtar->addToItems("Hat");
					layout[i][j] = ' ';
				}
			}
		}
	}

	// Show the movement of Morinehtar on the map
	layout[Morinehtar->getRowOld()][Morinehtar->getColOld()] = ' ';
	layout[Morinehtar->getRowNew()][Morinehtar->getColNew()] = 'W';

	// Remove one health value from the Wizard.
	Morinehtar->incrementHealth(-1);

	return room;
}

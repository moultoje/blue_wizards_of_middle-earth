/*******************************************************************************
** Program Name: startingRoom.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for the Starting Room class. Declares the 
**				constructor and the printLayout function of the class.
*******************************************************************************/

#ifndef STARTINGROOM_HPP
#define STARTINGROOM_HPP

#include "space.hpp"
#include "wizard.hpp"

class StartingRoom : public Space
{
	private:


	protected:


	public:
		StartingRoom(Wizard *wizInput);
		void printLayout();
};

#endif

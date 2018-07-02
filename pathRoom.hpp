/*******************************************************************************
** Program Name: pathRoom.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for the Path Room class. Declares the constructor
**				and the printLayout function of the class.
*******************************************************************************/

#ifndef PATHROOM_HPP
#define PATHROOM_HPP

#include "space.hpp"
#include "wizard.hpp"

class PathRoom : public Space
{
	private:


	protected:


	public:
		PathRoom(Wizard *wizInput);
		void printLayout();
		void unlockDoor();
};

#endif

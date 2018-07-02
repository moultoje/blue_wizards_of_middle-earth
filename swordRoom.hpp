/*******************************************************************************
** Program Name: swordRoom.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for the Sword Room class. Declares the constructor
**				and the printLayout function of the class.
*******************************************************************************/

#ifndef SWORDROOM_HPP
#define SWORDROOM_HPP

#include "space.hpp"
#include "wizard.hpp"

class SwordRoom : public Space
{
	private:


	protected:


	public:
		SwordRoom(Wizard *wizInput);
		void printLayout();
};

#endif

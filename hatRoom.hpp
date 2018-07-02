/*******************************************************************************
** Program Name: hatRoom.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for the Hat Room class. Declares the constructor and
**				the printLayout function of the class.
*******************************************************************************/

#ifndef HATROOM_HPP
#define HATROOM_HPP

#include "space.hpp"
#include "wizard.hpp"

class HatRoom : public Space
{
	private:


	protected:


	public:
		HatRoom(Wizard *wizInput);
		void printLayout();
};

#endif

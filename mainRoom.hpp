/*******************************************************************************
** Program Name: mainRoom.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for the Main Room class. Declares the constructor
**				and the printLayout function of the class.
*******************************************************************************/

#ifndef MAINROOM_HPP
#define MAINROOM_HPP

#include "space.hpp"
#include "wizard.hpp"

class MainRoom : public Space
{
	private:


	protected:


	public:
		MainRoom(Wizard *wizInput);
		void printLayout();
};

#endif

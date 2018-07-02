/*******************************************************************************
** Program Name: romestamoRoom.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for the Romestamo Room class. Declares the 
**				constructor and the printLayout function of the class.
*******************************************************************************/

#ifndef ROMESTAMOROOM_HPP
#define ROMESTAMOROOM_HPP

#include "space.hpp"
#include "wizard.hpp"

class RomestamoRoom : public Space
{
	private:


	protected:


	public:
		RomestamoRoom(Wizard *wizInput);
		void printLayout();
};

#endif

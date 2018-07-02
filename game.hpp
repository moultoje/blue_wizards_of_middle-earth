/*******************************************************************************
** Program Name: game.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for the game class. Creates the wizard object and
**				all the room objects as private and declares the constructor,
**				destructor, and play function as public.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "wizard.hpp"
#include "space.hpp"

class Game
{
	private:
		Wizard *Morinehtar;
		Space *currentR;
		Space *startingR;
		Space *mainR;
		Space *swordR;
		Space *hatR;
		Space *pathR;
		Space *RomestamoR;

	protected:
		

	public:
		Game();
		~Game();
		void play();
};

#endif

/*******************************************************************************
** Program Name: space.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for Space class. Creates 4 space pointers (to 
**				adjacent rooms), a 2d array for the map, and a wizard object as
**				protected variables. Declares the constructor, destructor, 
**				getters, setters, a move function, and a virtual printing
**				function.
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "wizard.hpp"

//class Wizard; // Forward delcaration
// found in https://stackoverflow.com/questions/3608305/class-name-does-not-
// name-a-type-in-c

class Space
{
	private:


	protected:
		Space *top;
		Space *right;
		Space *bottom;
		Space *left;
		char **layout;
		Wizard *Morinehtar;

	public:
		Space(Wizard *);
		virtual ~Space();
		Space * move(Space *);
		virtual void printLayout() = 0;
		void setTop(Space *);
		Space * getTop();
		void setRight(Space *);
		Space * getRight();
		void setBottom(Space *);
		Space * getBottom();
		void setLeft(Space *);
		Space * getLeft();
};

#endif

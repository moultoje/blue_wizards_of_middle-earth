/*******************************************************************************
** Program Name: wizard.hpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Header file for Wizard class. Adds the current health and 
**				maximum allowable health, a vector of items, and the new and old
**				row and column positions to the private members. Declares the
**				constructor, destructor, getters, setters, a move function, and
**				a function to increment the wizard's health.
*******************************************************************************/

#ifndef WIZARD_HPP
#define WIZARD_HPP

#include <vector>
#include <string>

class Wizard
{
	private:
		int curHealth;
		int totHealth;
		std::vector<std::string> items;
		int colNew;
		int rowNew;
		int colOld;
		int rowOld;

	protected:


	public:
		Wizard();
		~Wizard();
		void move(int, char **);
		void incrementHealth(int);
		void setHealth(int);
		int getCurHealth();
		int getTotHealth();
		void addToItems(std::string);
		std::string getItems(int);
		void setColNew(int);
		void setRowNew(int);
		int getColNew();
		int getColOld();
		int getRowNew();
		int getRowOld();
};

#endif

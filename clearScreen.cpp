/*******************************************************************************
** Program Name: clearScreen.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: The implementation for clearing the output screen.
*******************************************************************************/

#include "clearScreen.hpp"
#include <iostream>
#include <string>

void clearScreen()
{
	std::cout << std::string(100, '\n');

	return;
}

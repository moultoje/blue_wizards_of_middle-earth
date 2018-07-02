/*******************************************************************************
** Program Name: validate.cpp
** Author: Jeffrey Moulton (https://github.com/moultoje)
** Version: 1.0
** Description: Implementation file for validate functions.
*******************************************************************************/

#include "validate.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <cctype>
#include <string>
#include <sstream>

/*******************************************************************************
** validateInt
**		Validates that the user inputs an integer value to begin the quest. A 
**		valid input can be any integer.
** Arguments: N/A
** Returns: N/A
*******************************************************************************/
void validateInt()
{
	// Get the integer input.
	std::string validInt;
	int tempInput = -2348745;
	int input = -3427364;
	std::cin >> validInt;

	// While loop to keep returning error messages for invalid inputs.
	while(input != tempInput)
	{
		if(validInt.find_first_not_of("1234567890-") !=
			std::string::npos)
		{
			std::cout << "\nThe input must be an integer.";
			std::cout << "\nPlease enter a number to begin your "
				  << "quest."
				  << std::endl;

			std::cin >> validInt;
		}
		else
		{
			tempInput = std::stoi(validInt, nullptr);

			input = tempInput;
		}
	}

	std::cin.ignore();

	return;
}

/*******************************************************************************
** validateAction
**		Validates that the user inputs an integer value to complete an action.
**		A valid input can be 1, 2, 3, 4, or 5.
**	Arguments:
**		int *input - a pointer to the user's input
**	Returns: N/A
*******************************************************************************/
void validateAction(int *input)
{
	// Get the integer input.
	std::string validInt;
	int tempInput = -2348745;
	*input = -3427364;
	std::cin >> validInt;

	// While loop to keep returning error messages for invalid inputs.
	while(*input != tempInput)
	{
		if(validInt.find_first_not_of("1234567890-") !=
			std::string::npos)
		{
			std::cout << "\nThe input must be an integer.";
			std::cout << "\nPlease enter your action: "
				  << std::endl;

			std::cin >> validInt;
		}
		else
		{
			tempInput = std::stoi(validInt, nullptr);

			if(tempInput > 0 && tempInput < 6)
			{
				*input = tempInput;
			}
			else
			{
				std::cout << "\nThe input must be 1, 2, 3, 4, "
					  << "or 5.";
				std::cout << "\nPlease enter your action: ";

				std::cin >> validInt;
			}
		}
	}

	std::cin.ignore();

	return;
}

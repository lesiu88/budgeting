#include "Account.h"
#include "Budget.h"
#include "BudgetManager.h"

#include <iostream>
#include <vector>

int main()
{	
	// Create Account class to hold and manage all budgets
	Account* user = new Account("User");

	bool quit = false;		// Quit program?
	bool edit = false;		// Edit budget?

	std::string choice;		// Variable to hold user's choices

	std::string b_name;		// Name for a new budget
	double	b_amount;		// Amount for a new budget

	// Program Main Loop
	while (!quit)
	{
		std::cout << "Do you want to add or edit budget (Y/N)? ";
		std::cin >> choice;

		if (choice=="Y" || choice=="y")
		{
			std::cout << std::endl << "What's the name of the budget? ";
			std::cin >> b_name;

			// Check if budget already exists
			Budget* budget = user->budgetManager()->findBudget(b_name);

			if (budget != 0)
			{
				// If budget already exists, ask user if should it be edited
				std::cout << "Budget \"" << budget->name() << "\" already exists. Do you want to edit it (Y/N)?";
				std::cin >> choice;
				if ( choice=="Y" || choice=="y" )
				{
					edit = true;
				}	
				else
					continue;
			}

			// Set budget's amount
			std::cout << std::endl << "Amount to budget? ";
			std::cin >> b_amount;

			// Apply actions accordingly
			if (edit)
				user->budgetManager()->editBudget(budget, b_amount);
			else
				user->budgetManager()->createBudget(b_name, b_amount);
		}
		// Exit program
		else if (choice=="N" || choice=="n")
			quit = true;	
		else
			std::cout << "Unrecognized choice." << std::endl;
	}

	// Clean up
	delete user;
	return 0;
}

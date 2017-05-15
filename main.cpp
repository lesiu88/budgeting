#include "Account.h"
#include "Budget.h"
#include "BudgetManager.h"
#include "Transaction.h"

#include <iostream>
#include <vector>

int getUserChoice(int max)
{
	int choice = 0;
	int tries = 0;
	while(tries != 5)
	{
		std::cin >> choice;
		if (choice <= max && choice > 0)
			return choice;
		tries++;
	}
}

bool getUserYesNo()
{
	std::string choice;
	int tries = 0;
	while(tries != 5)
	{
		std::cin >> choice;
		if (choice == "Y" || choice == "y")
			return true;
		else if (choice == "N" || choice == "n")
			return false;
		else
			tries++;
	}
}

int main()
{	
	// Create Account class to hold and manage all budgets
	Account* user = new Account("User");

	bool quit = false;		// Quit program?
	bool edit = false;		// Edit budget?

	int choice;				// Variable to hold user's choices

	std::string b_name;		// Name for a new budget
	double	b_amount;		// Amount for a new budget

	// Program Main Loop
	while (!quit)
	{
		std::cout << "What do you want to do?"		<< std::endl;
		std::cout << "1 - Add or Edit Budget"		<< std::endl;
		std::cout << "2 - Add Transaction"			<< std::endl;
		std::cout << "3 - Quit"						<< std::endl;

		choice = getUserChoice(3);

		if (choice == 1)
		{
			if (user->budgetManager()->empty())
			{
				std::cout << "No budgets found."		<< std::endl;
				std::cout << "Creating new budget..."	<< std::endl;
			}

			else
			{
				std::cout << "1 - Add New Budget"		<< std::endl;
				user->budgetManager()->listBudgets();
			}
			std::cout << std::endl << "What's the name of the budget? ";
			std::cin >> b_name;

			// Check if budget already exists
			Budget* budget = user->budgetManager()->findBudget(b_name);

			if (budget != 0)
			{
				// If budget already exists, ask user if should it be edited
				std::cout << "Budget \"" << budget->name() << "\" already exists. Do you want to edit it (Y/N)?";
				if ( getUserYesNo() )
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
		else if (choice == 3)
			quit = true;	
		else 
			std::cout << "Unrecognized choice." << std::endl;
	}

	// Clean up
	delete user;
	return 0;
}

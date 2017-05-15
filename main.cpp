#include "Budget.h"
#include "BudgetManager.h"

#include <iostream>
#include <vector>
int main()
{	
	BudgetManager* budgetManager = new BudgetManager();

	bool quit = false;		// Quit program?
	bool edit = false;		// Edit budget?

	std::string choice;		// Variable to hold user's choices

	std::string b_name;		// Name for a new budget
	double	b_amount;		// Amount for a new budget

	while (!quit)
	{
		std::cout << "Do you want to add or edit budget (Y/N)? ";
		std::cin >> choice;

		if (choice=="Y" || choice=="y")
		{
			std::cout << std::endl << "What's the name of the budget? ";
			std::cin >> b_name;
			Budget* budget = budgetManager->findBudget(b_name);

			if (budget != 0)
			{
				std::cout << "Budget \"" << budget->name() << "\" already exists. Do you want to edit it (Y/N)?";
				std::cin >> choice;
				if ( choice=="Y" || choice=="y" )
				{
					edit = true;
				}	
				else
					continue;
			}

			std::cout << std::endl << "Amount to budget? ";
			std::cin >> b_amount;
			if (edit)
				budgetManager->editBudget(budget, b_amount);
			else
				budgetManager->createBudget(b_name, b_amount);
		}
		else if (choice=="N" || choice=="n")
			quit = true;	
		else
			std::cout << "Unrecognized choice." << std::endl;
	}
	std::cout << "New Budgeting application coming soon." << std::endl;
	delete budgetManager;
	return 0;
}

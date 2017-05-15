#include "Budget.h"

#include <iostream>
#include <vector>

bool createBudget(std::vector<Budget*> &b, std::string name, double amount)
{
	b.push_back( new Budget(name, amount) );	
}

Budget* findBudget(std::vector<Budget*> &b, std::string name)
{
	if ( !b.empty() )
	{
		for ( std::vector<Budget*>::iterator i=b.begin(); i!=b.end(); i++ )
		{
			if ( name == (*i)->name() )
				return (*i);
		}
	}
	return 0;
}

void editBudget(Budget* b, double amount)
{
	if (b->amount() != amount)
	{
		std::cout << "Budget's \"" << b->name() << "\" amount changed from " << b->amount() << " to ";
		b->setAmount(amount);
		std::cout << b->amount() << std::endl;
	}
	else
	{
		std::cout << "\"" << b->name() << "\" amount was already at " << b->amount() << std::endl;
		std::cout << "No changes required." << std::endl;
	}
}

int main()
{	
	std::vector<Budget*> budgets;

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
			Budget* budget = findBudget(budgets, b_name);

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
				editBudget(budget, b_amount);
			else
				createBudget(budgets, b_name, b_amount);
		}
		else if (choice=="N" || choice=="n")
			quit = true;	
		else
			std::cout << "Unrecognized choice." << std::endl;
	}
	
	if ( !budgets.empty() )
	{
		for (std::vector<Budget*>::iterator i=budgets.begin(); i!=budgets.end(); i++)
		{
			std::cout << (*i)->name() << std::endl;
		}

		for (std::vector<Budget*>::iterator i=budgets.begin(); i!=budgets.end(); i++)
		{
			delete (*i);
		}
		budgets.clear();
	}

	std::cout << "New Budgeting application coming soon." << std::endl;
	return 0;
}

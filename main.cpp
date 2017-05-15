#include "Budget.h"

#include <iostream>
#include <vector>

bool createBudget(std::vector<Budget*> &b, std::string name, double amount)
{
	b.push_back( new Budget(name, amount) );	
}

int main()
{	
	std::vector<Budget*> budgets;

	bool quit = false;
	std::string choice;
	std::string b_name;
	double	b_amount;

	while (!quit)
	{
		std::cout << "Do you want to add new budget (Y/N)? ";
		std::cin >> choice;

		if (choice=="Y" || choice=="y")
		{
			std::cout << std::endl << "What's the name of the budget? ";
			std::cin >> b_name;
			std::cout << std::endl << "Amount to budget? ";
			std::cin >> b_amount;
			createBudget(budgets, b_name, b_amount);
		}
		else if (choice=="N" || choice=="n")
			quit = true;	
		else
			std::cout << "Unrecognized choice." << std::endl;
	}

	budgets.push_back(new Budget("Oplaty", 1738));

	for (std::vector<Budget*>::iterator i=budgets.begin(); i!=budgets.end(); i++)
	{
		std::cout << (*i)->name() << std::endl;
	}

	for (std::vector<Budget*>::iterator i=budgets.begin(); i!=budgets.end(); i++)
	{
		delete (*i);
	}
	budgets.clear();

	std::cout << "New Budgeting application coming soon." << std::endl;
	return 0;
}

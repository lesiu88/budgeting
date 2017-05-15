#ifndef _BUDGETMANAGER_H_
#define _BUDGETMANAGER_H_

/*
	class BudgetManager

	Purpose: class to hold budgets and manage them
*/

class Budget;

#include <string>
#include <vector>

class BudgetManager
{
	public:
		~BudgetManager();

		bool createBudget(std::string, double);	// Create new budget
		Budget* findBudget(std::string);		// Find budget
		Budget* findBudget(int);
		void editBudget(Budget*, double);		// Edit budget
		bool empty();							// Check if there are budgets
		void listBudgets();
	private:
		std::vector<Budget*> p_budgets;			// vector to hold budgets
};

#endif


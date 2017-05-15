#ifndef _BUDGETMANAGER_H_
#define _BUDGETMANAGER_H_

class Budget;

#include <string>
#include <vector>

class BudgetManager
{
	public:
		~BudgetManager();

		bool createBudget(std::string, double);
		Budget* findBudget(std::string);
		void editBudget(Budget*, double);
	private:
		std::vector<Budget*> p_budgets;
};

#endif


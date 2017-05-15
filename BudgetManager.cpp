#include "BudgetManager.h"

#include "Budget.h"

bool BudgetManager::createBudget(std::string name, double amount)
{
	if ( !findBudget(name) )
	{
		this->p_budgets.push_back( new Budget(name, amount) );	
		return true;
	}
	else
		return false;
}

Budget* BudgetManager::findBudget(std::string name)
{
	if ( !this->p_budgets.empty() )
	{
		for ( std::vector<Budget*>::iterator i=this->p_budgets.begin(); i!=this->p_budgets.end(); i++ )
		{
			if ( name == (*i)->name() )
				return (*i);
		}
	}
	return 0;
}

void BudgetManager::editBudget(Budget* b, double amount)
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

BudgetManager::~BudgetManager()
{
	if ( !this->p_budgets.empty() )
	{
		/*	This loop was used for debugging, prints out all of the budgets before deletion

		for (std::vector<Budget*>::iterator i=this->p_budgets.begin(); i!=this->p_budgets.end(); i++)
		{
			std::cout << (*i)->name() << std::endl;
		}
		*/

		for (std::vector<Budget*>::iterator i=this->p_budgets.begin(); i!=this->p_budgets.end(); i++)
		{
			delete (*i);
		}
		this->p_budgets.clear();
	}
}

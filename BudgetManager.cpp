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

Budget* BudgetManager::findBudget(int id)
{
	if ( !this->p_budgets.empty() )
	{
		for ( std::vector<Budget*>::iterator i=this->p_budgets.begin(); i!=this->p_budgets.end(); i++ )
		{
			if ( id == (*i)->id() )
				return (*i);
		}
	}
	return 0;
}

void BudgetManager::editBudget(Budget* b, double amount)
{
	if (b == 0)
	{
		std::cout << "Fatal Error: Trying to edit NULL pointer!" << std::endl;
		throw;
	}
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

bool BudgetManager::empty()
{
	if (this->p_budgets.empty())
		return true;
	return false;
}

void BudgetManager::listBudgets()
{
	for (std::vector<Budget*>::iterator i=this->p_budgets.begin(); i!=this->p_budgets.end(); i++)
	{
		std::cout << (*i)->id() << "\t" << (*i)->name() << " [" << (*i)->amount() << "]" << std::endl;
	}
	// TODO
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

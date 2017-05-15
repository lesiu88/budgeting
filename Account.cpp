#include "Account.h"

#include "BudgetManager.h"

Account::Account(std::string username)
{
	this->p_username = username;
	this->p_bm = new BudgetManager();
}

Account::~Account()
{
	delete this->p_bm;
}

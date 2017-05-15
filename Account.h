#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class BudgetManager;

#include <string>
#include <map>

class Account
{
	public:
		Account(std::string);
		~Account();

		BudgetManager*	budgetManager() const { return this->p_bm; }
		std::string		username() const { return this->p_username; }

	private:
		std::string		p_username;
		BudgetManager*	p_bm;
};

#endif


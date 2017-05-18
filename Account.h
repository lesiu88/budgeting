#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class BudgetManager;
class Transaction;

#include <string>
#include <vector>

class Account
{
	public:
		Account(std::string);
		~Account();

		void			addTransaction(Transaction*);

		BudgetManager*	budgetManager() const { return this->p_bm; }
		std::string		username() const { return this->p_username; }

	private:
		std::string		p_username;
		BudgetManager*	p_bm;
		std::vector<Transaction*> p_transactions;
};

#endif


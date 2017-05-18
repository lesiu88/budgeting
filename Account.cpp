#include "Account.h"
#include "BudgetManager.h"
#include "Transaction.h"

Account::Account(std::string username)
{
	this->p_username = username;
	this->p_bm = new BudgetManager();
}

Account::~Account()
{
	delete this->p_bm;

	if ( !this->p_transactions.empty() )
	{
		for ( std::vector<Transaction*>::iterator i = p_transactions.begin(); i != p_transactions.end(); i++ )
		{
			delete (*i);
		}
		this->p_transactions.clear();
	}
}

void Account::addTransaction(Transaction* transaction)
{
	if ( transaction != 0 )
		this->p_transactions.push_back(transaction);
}

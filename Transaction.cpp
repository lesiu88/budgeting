#include "Transaction.h"

Transaction::Transaction(std::string budget, double amount, short type)
{
	this->p_budget = budget;
	this->p_amount = amount;

	if (type == TYPE_DEBT)
		this->p_amount *= -1;
}

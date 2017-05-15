#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>

const short	TYPE_DEBT = 0;
const short TYPE_CREDIT = 1;

class Transaction
{
	public:
		Transaction(std::string, double, short);

		double amount() const { return this->p_amount; }
		std::string budget() const { return this->p_budget; }
	private:
		double p_amount;
		std::string p_budget;
};

#endif


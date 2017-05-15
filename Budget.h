#ifndef BUDGET_H_
#define BUDGET_H_

/*
	class Budget
	Puprose: class holding budget data
*/

#include <iostream>
#include <string>

class Budget
{
	public:
		Budget(std::string, double);
		~Budget();

		std::string		name() const { return this->p_name; }
		double			amount() const { return this->p_amount; }

		void			setAmount(double amount) { this->p_amount = amount; }
	private:
		std::string		p_name;
		double			p_amount;
};

#endif


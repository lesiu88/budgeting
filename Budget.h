#ifndef BUDGET_H_
#define BUDGET_H_

#include <iostream>
#include <string>

class Budget
{
	public:
		Budget(std::string, double);
		~Budget();

		std::string		name() const { return this->p_name; }
	private:
		std::string		p_name;
		double			p_amount;
};


#endif


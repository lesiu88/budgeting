#include "Budget.h"

Budget::Budget(std::string name, double amount)
{
	this->p_name = name;
	this->p_amount = amount;
}

Budget::~Budget()
{
	std::cout << "Budget \"" << this->p_name << "\" deleted." << std::endl;
}


#include "Budget.h"

int Budget::budget_id = 10;

Budget::Budget(std::string name, double amount)
{
	this->p_name = name;
	this->p_amount = amount;
	budget_id++;
	this->p_id = budget_id;
}

Budget::~Budget()
{
	std::cout << "Budget \"" << this->p_name << "\" deleted." << std::endl;
}


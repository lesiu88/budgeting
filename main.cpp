#include <iostream>

class Budget
{
	public:
		Budget(std::string, double);
	private:
		std::string		p_name;
		double			p_amount;
};

Budget::Budget(std::string name, double amount)
{
	this->p_name = name;
	this->p_amount = amount;
}

int main()
{
	std::cout << "New Budgeting application coming soon." << std::endl;
	return 0;
}

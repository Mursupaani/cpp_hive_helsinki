#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("Robotomy Request Form", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
AForm("Robotomy Request Form", 72, 45, other.getTarget())
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

void RobotomyRequestForm::executeForm(void) const
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 1);

	int randomNum = dist(gen);
	if (randomNum % 2 == 0)
		std::cout << "!!!... LOUD DRILLING NOISES ...!!! " << this->getTarget() << " has been robotomized.\n";
	else
		std::cout << "Failed to robotomize " << this->getTarget() << "\n";
}

#pragma once
#include "AForm.hpp"
#include <string>
#include <iostream>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void) = delete;
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other) = delete;
	~RobotomyRequestForm(void);

	void executeForm(void) const override;
};

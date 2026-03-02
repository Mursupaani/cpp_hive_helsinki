#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void) = delete;
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other) = delete;
	~PresidentialPardonForm(void);

	void executeForm(void) const override;
};

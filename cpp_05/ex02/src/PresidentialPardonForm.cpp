#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("Presidential Pardon Form", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
AForm("Presidential Pardon Form", 25, 5, other.getTarget())
{}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

void PresidentialPardonForm::executeForm(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}

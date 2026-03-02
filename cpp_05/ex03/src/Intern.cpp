#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	for (int i = 0; i < 3; ++i)
	{
		if (name == _formNames[i])
		{
			std::cout << "Intern creates '" << _formNames[i] << "' form.\n";
			return (this->*_forms[i])(target);
		}
	}
	std::cout << "Form '" << name << "' not found.\n";
	return (nullptr);
}

AForm *Intern::_newShrubberyCreationForm(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::_newRobotobyRequestForm(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::_newPresidentialPardon(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}


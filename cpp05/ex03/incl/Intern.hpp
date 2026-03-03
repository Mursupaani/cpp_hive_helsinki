#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	AForm *_newShrubberyCreationForm(const std::string &target) const;
	AForm *_newRobotobyRequestForm(const std::string &target) const;
	AForm *_newPresidentialPardon(const std::string &target) const;
	AForm *(Intern::*_forms[3])(const std::string&) const
		{
			&Intern::_newShrubberyCreationForm,
			&Intern::_newRobotobyRequestForm,
			&Intern::_newPresidentialPardon,
		};
	std::string _formNames[3] =
		{
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
public:
	Intern(void) = default;
	Intern(const Intern &other) = default;
	Intern &operator=(const Intern &other) = default;
	~Intern(void) = default;

	AForm *makeForm(const std::string &name, const std::string &target) const;
};

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm("Shrubbery Creation Form", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
AForm("Shrubbery Creation Form", 145, 137, other.getTarget())
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

void ShrubberyCreationForm::executeForm(void) const
{
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream file(fileName);

	if (!file.is_open())
		std::cout << "Failed to create or open " << fileName << "\n";
	file << this->getTarget() << " is so nice now :)\n\n"
	"    ^      (()()())       ^\n"
	"   / \\    (()(())())     / \\\n"
	"  /   \\    (()()())     /   \\\n"
	"  -----       ||        -----\n"
	"   | |        ||         | |\n"
	;
}

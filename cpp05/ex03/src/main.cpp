/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:56:41 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/23 17:12:21 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	{
		std::cout << "----------TEST 1----------\n\n";
		Bureaucrat sign("Signer", 146);
		Bureaucrat execute("Executor", 138);
		AForm *form = intern.makeForm("shrubbery creation", "Yard");
		std::cout << "\n";
		std::cout << sign << "\n\n";
		std::cout << execute << "\n\n";
		std::cout << *form << "\n\n";
		execute.executeForm(*form);
		std::cout << "\n";
		sign.signForm(*form);
		sign.incrementGrade();
		std::cout << "Increment signer grade" << "\n";
		sign.signForm(*form);
		std::cout << "\n";
		execute.executeForm(*form);
		std::cout << "Increment executor grade" << "\n";
		execute.incrementGrade();
		execute.executeForm(*form);
		std::cout << "\n";
		delete form;
		std::cout << "\n";
	}
	{
		std::cout << "----------TEST 2----------\n\n";
		Bureaucrat sign("Signer", 73);
		Bureaucrat execute("Executor", 46);
		AForm *form = intern.makeForm("robotomy request", "Pekka");
		std::cout << "\n";
		std::cout << sign << "\n\n";
		std::cout << execute << "\n\n";
		std::cout << *form << "\n\n";
		execute.executeForm(*form);
		std::cout << "\n";
		sign.signForm(*form);
		sign.incrementGrade();
		std::cout << "Increment signer grade" << "\n";
		sign.signForm(*form);
		std::cout << "\n";
		std::cout << "Increment executor grade" << "\n";
		execute.incrementGrade();
		for (int i = 0; i < 10; ++i)
		{
			std::cout << i << ": ";
			execute.executeForm(*form);
		}
		delete form;
		std::cout << "\n";
	}
	{
		std::cout << "----------TEST 3----------\n\n";
		Bureaucrat sign("Signer", 26);
		Bureaucrat execute("Executor", 6);
		AForm *form = intern.makeForm("presidential pardon", "Pekka");
		std::cout << "\n";
		std::cout << sign << "\n\n";
		std::cout << execute << "\n\n";
		std::cout << *form << "\n\n";
		execute.executeForm(*form);
		std::cout << "\n";
		sign.signForm(*form);
		sign.incrementGrade();
		std::cout << "Increment signer grade" << "\n";
		sign.signForm(*form);
		std::cout << "\n";
		execute.executeForm(*form);
		std::cout << "Increment executor grade" << "\n";
		execute.incrementGrade();
		execute.executeForm(*form);
		delete form;
		std::cout << "\n";
	}
	{
		std::cout << "----------TEST 4----------\n\n";
		Intern test(intern);
		AForm *form = test.makeForm("shrubbery creation", "Back yard");
		delete form;
		Intern test2 = test;
		form = test2.makeForm("robotomy request", "Bjorn");
		delete form;
		Intern test3;
		test3 = test2;
		form = test3.makeForm("presidential pardon", "Hans");
		delete form;
	}
	{
		std::cout << "----------TEST 5----------\n\n";
		AForm *form = intern.makeForm("hive graduation", "anpollan");
		if (form == nullptr)
			std::cout << "Intern returned a nullptr\n";
	}
}

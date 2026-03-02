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

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		std::cout << "----------TEST 1----------\n\n";
		Bureaucrat sign("Signer", 146);
		Bureaucrat execute("Executor", 138);
		ShrubberyCreationForm form("Park");
		ShrubberyCreationForm form2("Yard");
		std::cout << sign << "\n\n";
		std::cout << execute << "\n\n";
		std::cout << form << "\n\n";
		execute.executeForm(form);
		std::cout << "\n";
		sign.signForm(form);
		sign.incrementGrade();
		std::cout << "Increment signer grade" << "\n";
		sign.signForm(form);
		std::cout << "\n";
		execute.executeForm(form);
		std::cout << "Increment executor grade" << "\n";
		execute.incrementGrade();
		execute.executeForm(form);
		std::cout << "\n";
		sign.signForm(form2);
		execute.executeForm(form2);
		std::cout << "\n";
	}
	{
		std::cout << "----------TEST 2----------\n\n";
		Bureaucrat sign("Signer", 73);
		Bureaucrat execute("Executor", 46);
		RobotomyRequestForm form("Pekka");
		std::cout << "\n";
		std::cout << sign << "\n\n";
		std::cout << execute << "\n\n";
		std::cout << form << "\n\n";
		execute.executeForm(form);
		std::cout << "\n";
		sign.signForm(form);
		sign.incrementGrade();
		std::cout << "Increment signer grade" << "\n";
		sign.signForm(form);
		std::cout << "\n";
		std::cout << "Increment executor grade" << "\n";
		execute.incrementGrade();
		for (int i = 0; i < 10; ++i)
		{
			std::cout << i << ": ";
			execute.executeForm(form);
		}
		std::cout << "\n";
	}
	{
		std::cout << "----------TEST 3----------\n\n";
		Bureaucrat sign("Signer", 26);
		Bureaucrat execute("Executor", 6);
		PresidentialPardonForm form("Pekka");
		std::cout << "\n";
		std::cout << sign << "\n\n";
		std::cout << execute << "\n\n";
		std::cout << form << "\n\n";
		execute.executeForm(form);
		std::cout << "\n";
		sign.signForm(form);
		sign.incrementGrade();
		std::cout << "Increment signer grade" << "\n";
		sign.signForm(form);
		std::cout << "\n";
		execute.executeForm(form);
		std::cout << "Increment executor grade" << "\n";
		execute.incrementGrade();
		execute.executeForm(form);
		std::cout << "\n";
	}
	{
		std::cout << "----------TEST 4----------\n\n";
		ShrubberyCreationForm test("test");
		ShrubberyCreationForm test_copy(test);
		std::cout << test << "\n";
		std::cout << test_copy << "\n";
		std::cout << "\n";
		// test = test_copy;
	}
	{
		std::cout << "-----------TEST 6----------\n\n";
		RobotomyRequestForm test("test");
		RobotomyRequestForm test_copy(test);
		std::cout << test << "\n";
		std::cout << test_copy << "\n";
		std::cout << "\n";
		// test = test_copy;
	}
	{
		std::cout << "----------TEST 7----------\n\n";
		PresidentialPardonForm test("test");
		PresidentialPardonForm test_copy(test);
		std::cout << test << "\n";
		std::cout << test_copy << "\n";
		std::cout << "\n";
		// test = test_copy;
	}
}

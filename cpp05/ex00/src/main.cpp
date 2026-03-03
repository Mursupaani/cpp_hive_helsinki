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

int main(void)
{
	{
		std::cout << "TEST 1:\n\n";
		Bureaucrat test;
		std::cout << test << "\n";
		try
		{
			test.decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << test << "\n";
		std::cout << "Increment bureucrat's grade\n";
		test.incrementGrade();
		std::cout << test << "\n";
	}
	{
		std::cout << "\nTEST 2:\n\n";
		Bureaucrat test("Pekka", 1);
		std::cout << test << "\n";
		try
		{
			test.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << test << "\n";
		std::cout << "Decrement bureucrat's grade\n";
		test.decrementGrade();
		std::cout << test << "\n";
	}
	{
		std::cout << "\nTEST 3:\n\n";
		Bureaucrat test("Pekka", 1);
		Bureaucrat test_copy(test);
		std::cout << "Original\n";
		std::cout << test << "\n";
		std::cout << "Copy of original\n";
		std::cout << test_copy << "\n";
		std::cout << "Copy assignment test_copy = test\n";
		test_copy = test;
		std::cout << "Decrement original's grade\n";
		test.decrementGrade();
		std::cout << "Original\n";
		std::cout << test << "\n";
		std::cout << "Copy of original\n";
		std::cout << test_copy << "\n";
	}
	{
		std::cout << "\nTEST 4:\n\n";
		try
		{
			Bureaucrat test("Pekka", 0);
			std::cout << test << "\n";
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << "\n";
		}
	}
	{
		std::cout << "\nTEST 5:\n\n";
		try
		{
			Bureaucrat test("Pekka", -1);
			std::cout << test << "\n";
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << "\n";
		}
	}
	{
		std::cout << "\nTEST 6:\n\n";
		try
		{
			Bureaucrat test("Pekka", 200);
			std::cout << test << "\n";
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << "\n";
		}
	}
}

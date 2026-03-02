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
		std::cout << "TEST1:\n\n";
		Bureaucrat pekka("Pekka", 11);
		Form form("Test", 10, 15);
		std::cout << pekka << "\n\n";
		std::cout << form << "\n\n";
		pekka.signForm(form);
		std::cout << "\nIncrement Pekka's grade and try again.\n\n";
		pekka.incrementGrade();
		std::cout << pekka << "\n\n";
		pekka.signForm(form);
		std::cout << form << "\n";
	}
	{
		std::cout << "\n\nTEST2:\n\n";
		Bureaucrat pekka("Pekka", 1);
		try
		{
			Form form("Test", 1, 15);
			std::cout << form << "\n";
			std::cout << pekka << "\n";
			pekka.signForm(form);
			std::cout << form << "\n";
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Form::GradeTooHighException&e)
		{
			std::cout << e.what() << "\n";
		}
	}
	{
		Bureaucrat pekka("Pekka", 1);
		try
		{
			Form form("Test", 1, 0);
			std::cout << form << "\n";
			std::cout << pekka << "\n";
			pekka.signForm(form);
			std::cout << form << "\n";
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Form::GradeTooHighException&e)
		{
			std::cout << e.what() << "\n";
		}
	}
	{
		std::cout << "\n\nTEST3:\n\n";
		Bureaucrat pekka("Pekka", 1);
		try
		{
			Form form("Test", 200, 1);
			std::cout << form << "\n";
			std::cout << pekka << "\n";
			pekka.signForm(form);
			std::cout << form << "\n";
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Form::GradeTooHighException&e)
		{
			std::cout << e.what() << "\n";
		}
		try
		{
			Form form("Test", 1, 200);
			std::cout << form << "\n";
			std::cout << pekka << "\n";
			pekka.signForm(form);
			std::cout << form << "\n";
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Form::GradeTooHighException&e)
		{
			std::cout << e.what() << "\n";
		}
	}
	{
		std::cout << "\n\nTEST4:\n\n";
		Bureaucrat pekka("Pekka", 150);
		Form form("Test", 150, 1);
		Form form_copy(form);
		std::cout << pekka << "\n\n";
		std::cout << "Original " << form << "\n\n";
		std::cout << "Copy " << form_copy << "\n\n";
		pekka.signForm(form);
		std::cout << "\nOriginal " << form << "\n\n";
		std::cout << "Copy " << form_copy << "\n\n";
	}
	{
		std::cout << "\n\nTEST5:\n\n";
		Bureaucrat pekka("Pekka", 1);
		Form form("Test", 150, 1);
		std::cout << pekka << "\n\n";
		std::cout << "Original " << form << "\n\n";
		pekka.signForm(form);
		Form form_copy(form);
		std::cout << "\nOriginal " << form << "\n\n";
		std::cout << "Copy " << form_copy << "\n\n";
	}
}

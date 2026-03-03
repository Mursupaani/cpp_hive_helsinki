/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:45:00 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/23 17:10:00 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class AForm;

class Bureaucrat
{
private:
	static const unsigned int	_gradeMax = 1;
	static const unsigned int	_gradeMin = 150;
	const std::string	_name;
	unsigned int		_grade;
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, const unsigned int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat(void) = default;

	static unsigned int getGradeMax(void);
	static unsigned int getGradeMin(void);

	std::string getName(void) const;
	unsigned int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm &f) const;
	void executeForm(AForm &f) const;

	class GradeTooHighException : public std::exception
	{
	private:
		std::string _message;
	public:
		GradeTooHighException(void) = default;
		~GradeTooHighException(void) = default;
		GradeTooHighException(const std::string &message);

		const char *what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
		{
	private:
		std::string _message;
	public:
		GradeTooLowException(void) = default;
		~GradeTooLowException(void) = default;
		GradeTooLowException(const std::string &message);
	
		const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &b);

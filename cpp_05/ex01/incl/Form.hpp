#pragma once
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
	bool				_isSigned;
public:
	Form(void) = delete;
	Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other) = delete;
	~Form(void);

	std::string getName(void) const;
	unsigned int getGradeToSign(void) const;
	unsigned int getGradeToExecute(void) const;
	bool getIsSigned(void) const;
	void beSigned(const Bureaucrat &b);

	class GradeTooLowException : std::exception
	{
	private:
		std::string _message;
	public:
		GradeTooLowException(void) = default;
		~GradeTooLowException(void) = default;
		GradeTooLowException(const std::string &message);

		const char *what(void) const noexcept override;
	};

	class GradeTooHighException : std::exception
	{
	private:
		std::string _message;
	public:
		GradeTooHighException(void) = default;
		~GradeTooHighException(void) = default;
		GradeTooHighException(const std::string &message);

		const char *what(void) const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &ostream, const Form &f);

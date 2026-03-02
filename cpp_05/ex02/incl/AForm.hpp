#pragma once
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>
#include <iostream>
#include <fstream>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
	const std::string	_target;
	bool				_isSigned;
public:
	AForm(void) = delete;
	AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute, const std::string &target);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other) = delete;
	virtual ~AForm(void);

	std::string getName(void) const;
	std::string getTarget(void) const;
	unsigned int getGradeToSign(void) const;
	unsigned int getGradeToExecute(void) const;
	bool getIsSigned(void) const;
	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const & executor) const;
	virtual void executeForm(void) const = 0;

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

	class FormNotSignedException : std::exception
	{
	private:
		std::string _message;
	public:
		FormNotSignedException(void) = default;
		~FormNotSignedException(void) = default;
		FormNotSignedException(const std::string &message);

		const char *what(void) const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &ostream, const AForm &f);

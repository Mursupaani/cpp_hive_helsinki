#include "Form.hpp"
#include <string>

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute) :
_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (_gradeToSign < Bureaucrat::getGradeMax())
		throw (Form::GradeTooHighException("Form's grade to sign can't be higher than " + std::to_string(Bureaucrat::getGradeMax())));
	else if (_gradeToSign > Bureaucrat::getGradeMin())
		throw (Form::GradeTooLowException("Form's grade to sign can't be lower than " + std::to_string(Bureaucrat::getGradeMin())));
	if (_gradeToExecute < Bureaucrat::getGradeMax())
		throw (Form::GradeTooHighException("Form's grade to execute can't be higher than " + std::to_string(Bureaucrat::getGradeMax())));
	else if (_gradeToExecute > Bureaucrat::getGradeMin())
		throw (Form::GradeTooLowException("Form's grade to execute can't be lower than " + std::to_string(Bureaucrat::getGradeMin())));
}

Form::Form(const Form &other) :
_name(other._name), _gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute), _isSigned(false)
{}

Form::~Form(void)
{}

std::string Form::getName(void) const
{
	return (_name);
}

unsigned int Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

bool Form::getIsSigned(void) const
{
	return (_isSigned);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
	{
		throw Form::GradeTooLowException(b.getName() + " could't sign '" + this->_name + "' because their grade is too low");
	}
}

std::ostream &operator<<(std::ostream &ostream, const Form &f)
{
	ostream << "Form:\n";
	ostream << "\tName: " << f.getName() << "\n";
	ostream << "\tGrade to sign: " << f.getGradeToSign() << "\n";
	ostream << "\tGrade to execute: " << f.getGradeToExecute() << "\n";
	ostream << "\tIs signed: " << (f.getIsSigned() == 1 ? "true" : "false");
	return (ostream);
}

Form::GradeTooLowException::GradeTooLowException(const std::string &message) : _message(message)
{}

Form::GradeTooHighException::GradeTooHighException(const std::string &message) : _message(message)
{}

const char *Form::GradeTooLowException::what(void) const noexcept
{
	return (_message.c_str());
}

const char *Form::GradeTooHighException::what(void) const noexcept
{
	return (_message.c_str());
}

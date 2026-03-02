#include "AForm.hpp"

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute, const std::string &target) :
_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target), _isSigned(false)
{
	if (_gradeToSign < Bureaucrat::getGradeMax())
		throw (AForm::GradeTooHighException("Form's grade to sign can't be higher than " + std::to_string(Bureaucrat::getGradeMax())));
	else if (_gradeToSign > Bureaucrat::getGradeMin())
		throw (AForm::GradeTooLowException("Form's grade to sign can't be lower than " + std::to_string(Bureaucrat::getGradeMin())));
	if (_gradeToExecute < Bureaucrat::getGradeMax())
		throw (AForm::GradeTooHighException("Form's grade to execute can't be higher than " + std::to_string(Bureaucrat::getGradeMax())));
	else if (_gradeToExecute > Bureaucrat::getGradeMin())
		throw (AForm::GradeTooLowException("Form's grade to execute can't be lower than " + std::to_string(Bureaucrat::getGradeMin())));
}

AForm::AForm(const AForm &other) :
_name(other._name), _gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute), _isSigned(false)
{}

AForm::~AForm(void)
{}

std::string AForm::getName(void) const
{
	return (_name);
}

std::string AForm::getTarget(void) const
{
	return (_target);
}

unsigned int AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

bool AForm::getIsSigned(void) const
{
	return (_isSigned);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
	{
		throw AForm::GradeTooLowException(b.getName() + " could't sign " + this->_name + " that targets " + this->getTarget() + " because their grade is too low");
	}
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (_isSigned == false)
		throw (AForm::FormNotSignedException(_name + " that targets " + _target + " is not signed so it can't be executed by " + executor.getName()));
	if (executor.getGrade() > _gradeToExecute)
		throw (AForm::GradeTooLowException(executor.getName() + " couldn't execute " + _name + " that targets " + _target + " because their grade is too low"));
	executeForm();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &message) : _message(message)
{}

const char *AForm::GradeTooLowException::what(void) const noexcept
{
	return (_message.c_str());
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &message) : _message(message)
{}

const char *AForm::GradeTooHighException::what(void) const noexcept
{
	return (_message.c_str());
}

AForm::FormNotSignedException::FormNotSignedException(const std::string &message) : _message(message)
{}

const char *AForm::FormNotSignedException::what(void) const noexcept
{
	return (_message.c_str());
}

std::ostream &operator<<(std::ostream &ostream, const AForm &f)
{
	ostream << "Form:\n";
	ostream << "\tName: " << f.getName() << "\n";
	ostream << "\tTarget: " << f.getTarget() << "\n";
	ostream << "\tGrade to sign: " << f.getGradeToSign() << "\n";
	ostream << "\tGrade to execute: " << f.getGradeToExecute() << "\n";
	ostream << "\tIs signed: " << (f.getIsSigned() == 1 ? "true" : "false");
	return (ostream);
}

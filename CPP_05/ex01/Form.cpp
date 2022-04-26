#include "Form.hpp"

Form::Form(void) : _grade_to_sign(1), _grade_to_exec(1)
{

}

Form::Form(std::string const name, int grade_to_sign, int grade_to_exec) : _name(name),
						_grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	this->_signed = false;
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw Form::GradeTooHighException();
	else if (this->_grade_to_sign > 150 || this->_grade_to_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _grade_to_sign(src._grade_to_sign),
								_grade_to_exec(src._grade_to_exec)
{
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw Form::GradeTooHighException();
	else if (this->_grade_to_sign > 150 || this->_grade_to_exec > 150)
		throw Form::GradeTooLowException();
	this->_signed = src._signed;
}

Form::~Form(void) {}

Form &Form::operator=(const Form &src)
{
	(void)src;
	return (*this);
}

std::string const &Form::getName(void) const
{
	return(this->_name);
}

int Form::getSignGrade(void) const
{
	return(this->_grade_to_sign);
}

int Form::getExecGrade(void) const
{
	return(this->_grade_to_exec);
}

bool Form::isSigned(void) const
{
	return(this->_signed);
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form:GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form:GradeTooLowException");
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << "Form: " << src.getName() 
		<< ", grade to sign: " << src.getSignGrade()
		<< ", grade to execute: " << src.getExecGrade()
		<< ", signed: " << (src.isSigned() ? "Yes" : "No");
	return (o);
}

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat(void)
{

}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	this->_grade = grade;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	this->_grade = src._grade;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::inc_grade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::dec_grade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form &form) const
{
	if (form.isSigned())
		std::cout << this->_name << " cannot sign " << form.getName()
			<< " because " << form.getName() << " is already signed" << std::endl;
	else if (this->_grade <= form.getSignGrade())
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	else
		std::cout << this->_name << " cannot sign " << form.getName()
			<< " because " << this->_name << "'s grade is too low" << std::endl;
}

void Bureaucrat::executeForm(Form const & form)
{
	bool is_executed = false;
	std::string err_msg;

	try
	{
		form.execute(*this);
		is_executed = true;
	}
	catch (ShrubberyCreationForm::FileStreamException &e)
	{
		err_msg = std::string("File Error: ") + e.what();
	}
	catch (std::exception &e)
	{
		err_msg = e.what();
	}

	if (is_executed)
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	else
		std::cout << this->_name << " cannot execute " << form.getName()
			<< " : " << err_msg << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (o);
}

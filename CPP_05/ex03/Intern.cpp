#include "Intern.hpp"

Intern::Intern(void)
{
	this->forms[0] = "Shrubbery Creation";
	this->forms[1] = "Robotomy Request";
	this->forms[2] = "Presidential Pardon";
	this->forms_f[0] = &ShrubberyCreationForm::newForm;
	this->forms_f[1] = &RobotomyRequestForm::newForm;
	this->forms_f[2] = &PresidentialPardonForm::newForm;
}

Intern::Intern(Intern const &src)
{
	for(int i = 0; i < 3; i++)
		this->forms[i] = src.forms[i];
}

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

Form *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	for (int i = 0; i < 3; i++)
	{
		if (this->forms[i].compare(formName) == 0)
		{
			Form *form = (*this->forms_f[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	throw Intern::FormNotFoundException(formName);
}

Intern::FormNotFoundException::FormNotFoundException(std::string const &formName) : std::exception()
{
	this->_msg = "Form with name " + formName + " is not found";
}

Intern::FormNotFoundException::~FormNotFoundException(void) throw () {}

const char* Intern::FormNotFoundException::what() const throw()
{
	return (this->_msg.c_str());
}


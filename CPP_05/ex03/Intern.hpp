#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);
		Intern & operator=(Intern const & src);

		Form *makeForm(std::string const &formName, std::string const &target) const;

		class FormNotFoundException : public std::exception
		{
			private:
				std::string _msg;
			public:
				virtual const char* what() const throw();
				FormNotFoundException(std::string const &formName);
				~FormNotFoundException(void) throw ();
		};
	private:
		std::string forms[3];
		Form *(*forms_f[3])(std::string const &target);
};

#endif /* INTERN_HPP */


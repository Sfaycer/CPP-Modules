#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string const name, int grade_to_sign, int grade_to_exec);
		Form(Form const &src);
		~Form(void);
		Form & operator=(Form const & src);

		std::string const &getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool isSigned(void) const;

		void beSigned(Bureaucrat const &bur);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		Form(void);
		bool _signed;
		std::string const _name;
		int const _grade_to_sign;
		int const _grade_to_exec;
};

std::ostream &operator<<(std::ostream &o, Form const &src);

#endif /* FORM_HPP */


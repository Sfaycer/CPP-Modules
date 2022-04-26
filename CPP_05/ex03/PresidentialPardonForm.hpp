#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

		void execute(Bureaucrat const & executor) const;
		static Form *newForm(std::string const &target);
	private:
		PresidentialPardonForm(void);
		std::string _target;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */


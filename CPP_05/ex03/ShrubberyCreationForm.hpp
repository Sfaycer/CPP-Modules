#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

		void execute(Bureaucrat const & executor) const;

		static Form *newForm(std::string const &target);
		class FileStreamException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		ShrubberyCreationForm(void);
		std::string _target;
		std::string _tree;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */


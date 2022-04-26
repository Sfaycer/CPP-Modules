#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		Bureaucrat & operator=(Bureaucrat const & src);

		std::string const &getName() const;
		int getGrade() const;
		void inc_grade();
		void dec_grade();

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
		std::string const _name;
		int _grade;
		Bureaucrat(void);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif /* BUREAUCRAT_HPP */


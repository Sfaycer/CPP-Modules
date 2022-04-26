#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <iterator>
#include <algorithm>

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);
		Span & operator=(Span const & src);

		void addNumber(int num);
		void addNumber(std::vector<int> const &src);
		void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		void addNumber(int from, int to);

		int shortestSpan(void) const;
		int longestSpan(void) const;

		class ExeptionalThrow : public std::exception
		{
			public:
				ExeptionalThrow(std::string const &message);
				~ExeptionalThrow(void) throw ();
				virtual const char *what() const throw();
			private:
				std::string message;
		};
	private:
		unsigned int max;
		std::vector<int> array;
};

#endif /* SPAN_HPP */


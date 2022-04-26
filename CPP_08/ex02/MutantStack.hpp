#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void) : std::stack<T, Container>() {}
		MutantStack(MutantStack<T, Container> const &src) : std::stack<T, Container>(src) {}
		virtual ~MutantStack(void) {}
		MutantStack & operator=(MutantStack const & src)
		{
			std::stack<T, Container>::operator =(src);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void)
		{
			return (this->c.begin());
		}
		iterator end(void)
		{
			return (this->c.end());
		}

		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		const_iterator begin() const
		{
			return (this->c.begin());
		}
		const_iterator end() const
		{
			return (this->c.end());
		}

		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() 
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend() 
		{
			return (this->c.rend());
		}

		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const 
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const
		{
			return (this->c.rend());
		}
};

#endif /* MUTANTSTACK_HPP */


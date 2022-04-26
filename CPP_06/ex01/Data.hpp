#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
	public:
		Data(void);
		Data(Data const &src);
		~Data(void);
		Data & operator=(Data const & src);

		void danger(void) const;
		void noDanger(void) const;
};

#endif /* DATA_HPP */

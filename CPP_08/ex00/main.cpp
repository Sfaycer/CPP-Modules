#include "easyfind.hpp"
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int incr(int i)
{
	return (++i);
}

int main(void)
{
	std::list<int> l;
	l.push_back(1);
	l.push_back(3);
	l.push_back(5);
	l.push_back(7);
	l.push_back(9);

	std::vector<int> v;
	v.resize(l.size());//needs to be resized for appropriate amount of elements. Otherwise segfault!
	std::transform(l.begin(), l.end(), v.begin(), incr);

	std::list<int>::iterator it_l;
	std::vector<int>::iterator it_v;

	int a = 5;
	int b = 8;

	it_l = easyfind(l, a);
	if (it_l != l.end())
		std::cout << a << " is a " << std::distance(l.begin(), it_l) << " element of list" << std::endl;
	else
		std::cout << a << " is not found in list" << std::endl;

	it_v = easyfind(v, b);
	if (it_v != v.end())
		std::cout << b << " is a " << std::distance(v.begin(), it_v) << " element of vector" << std::endl;
	else
		std::cout << b << " is not found in vector" << std::endl;

	return (0);
}

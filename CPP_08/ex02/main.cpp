#include "MutantStack.hpp"

int main(void)
{
	{
		std::cout << "========Subject Tests=======" << std::endl;
		MutantStack<int>    mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while(it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	srand(time(0));

	std::cout << "==============Iterator==============" << std::endl;
	MutantStack<int> st_1;
	for (size_t i = 0; i < 10; i++)
		st_1.push(rand() % 100);
	std::cout << "Top element: " << st_1.top() << std::endl;
	MutantStack<int>::iterator it_1 = st_1.begin();
	MutantStack<int>::iterator ite_1 = st_1.end();
	std::cout << "Elements: ";
	while(it_1 != ite_1)
	{
		std::cout << *it_1 << " ";
		++it_1;
	}
	std::cout << std::endl;


	std::cout << "==============Const_Iterator==============" << std::endl;
	MutantStack<int> st_2;
	for (size_t i = 0; i < 10; i++)
		st_2.push(rand() % 100);
	std::cout << "Top element: " << st_2.top() << std::endl;
	MutantStack<int>::const_iterator it_2 = st_2.begin();
	MutantStack<int>::const_iterator ite_2 = st_2.end();
	std::cout << "Elements: ";
	while(it_2 != ite_2)
	{
		std::cout << *it_2 << " ";
		++it_2;
	}
	std::cout << std::endl;


	std::cout << "==============Reverse_Iterator==============" << std::endl;
	MutantStack<int> st_3;
	for (size_t i = 0; i < 10; i++)
		st_3.push(rand() % 100);
	std::cout << "Top element: " << st_3.top() << std::endl;
	MutantStack<int>::reverse_iterator it_3 = st_3.rbegin();
	MutantStack<int>::reverse_iterator ite_3 = st_3.rend();
	std::cout << "Elements: ";
	while(it_3 != ite_3)
	{
		std::cout << *it_3 << " ";
		++it_3;
	}
	std::cout << std::endl;


	std::cout << "==============Const_Reverse_Iterator==============" << std::endl;
	MutantStack<int> st_4;
	for (size_t i = 0; i < 10; i++)
		st_4.push(rand() % 100);
	std::cout << "Top element: " << st_4.top() << std::endl;
	MutantStack<int>::const_reverse_iterator it_4 = st_4.rbegin();
	MutantStack<int>::const_reverse_iterator ite_4 = st_4.rend();
	std::cout << "Elements: ";
	while(it_4 != ite_4)
	{
		std::cout << *it_4 << " ";
		++it_4;
	}
	std::cout << std::endl;

	return (0);
}

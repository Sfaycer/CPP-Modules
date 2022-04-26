#include "main.hpp"

/*class Awesome
{
	public:
		Awesome(void): _n(42) {return; }
		int get(void) const {return this->_n;}
	private:
		int _n;
};
std::ostream & operator<<(std::ostream &o, Awesome const &rhs) {o << rhs.get(); return o;}
*/

void print_int(int const &d)
{
	std::cout << d << std::endl; 
}

int main(void)
{
	int arr1[] = {0,1,2,3,4,5,6,7};
	std::string arr2[] = {"Life","is","a","cycle"};

	std::cout << "=========PRINT_INT FUNCTION===========" << std::endl;
	iter(arr1, 8, print_int);
	std::cout << "=======PRINT TEMPLATE FUNCTION <int>========" << std::endl;
	iter(arr1, 8, print);
	std::cout << "=======PRINT TEMPLATE FUNCTION <string>========" << std::endl;
	iter(arr2, 4, print);

/*	std::cout << "======CHECKLIST======" << std::endl;
	int tab[] = {0,1,2,3,4};
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);
*/
	return (0);
}

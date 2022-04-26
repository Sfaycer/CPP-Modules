#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
	{
		Dog *b = new Dog;
		std::cout << std::endl;
		Dog d(*b);
		std::cout << std::endl;
		delete b;
		std::cout << std::endl;
		{
			Dog g;
			g = d;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "------------------------------" << std::endl;
		const Cat *b = new Cat;
		std::cout << std::endl;
		Cat d(*b);
		std::cout << std::endl;
		delete b;
		std::cout << std::endl;
		{
			Cat g;
			g = d;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "------------------------------" << std::endl;
		const Animal *a = new Dog;
		const Animal *b = new Cat;
		const Animal *c = new Dog;
		const Animal *d = new Cat;
		const Animal *arr [] = {a,b,c,d};
		std::cout << std::endl;
		for (int i = 0; i < 4; i++)
		{
			arr[i]->makeSound();
			delete arr[i];
		}
		std::cout << std::endl;
	}
	return (0);
}

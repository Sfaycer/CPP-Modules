#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{

}

Zombie::Zombie(void)
{
	std::string randomNames[] = {"Mike", "Ghazzy", "Grim", "Steward", "Elly", "Annie",
		"Stephany", "CuteDog", "Victor", "Clay", "Grey", "Clinton"};
	srand(time(0));
	this->_name = randomNames[rand() % ARRAYSIZEM(randomNames)];
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " finally found rest" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

//"use" method needs testing

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("Alex");

	AMateria* tmp;

	std::cout << "===============JIM=============" << std::endl;
	Character jim("Jim");
	tmp = src->createMateria("cure");
	jim.equip(tmp);
	tmp = src->createMateria("cure");
	jim.equip(tmp);
	AMateria *tmp2 = src->createMateria("cure"); //new instance for later deletion
	jim.equip(tmp2);
	tmp = src->createMateria("cure");
	jim.equip(tmp);
	tmp = src->createMateria("ice");
	jim.equip(tmp); //5th power, cannot equip
	for (int i = 0; i < 4; i++)
		jim.use(i, *me);
	delete tmp;
	jim.unequip(2);
	delete tmp2; //unequip(2) cannot delete, so we do it manually

	std::cout << "===============JIM_2=============" << std::endl;
	Character jim0(jim);
	Character jim2;
	jim2 = jim0;
	jim2.unequip(10);
	tmp = src->createMateria("ice");
	jim2.equip(tmp);
	for (int i = 0; i < 4; i++)
		jim2.use(i, *me);
	std::cout << "===============Alex=============" << std::endl;
	ICharacter* bob = new Character("bob");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("poison");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

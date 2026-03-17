#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"

int main()
{
	{
		std::cout << "===== TEST 1 =====" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << "\n===== TEST 2 : Unknown Materia type =====" << std::endl;
		IMateriaSource* src1 = new MateriaSource();
		src1->learnMateria(new Ice());

		AMateria* tmp1 = src1->createMateria("fire");

		if (!tmp1)
			std::cout << "Unknown materia correctly returns NULL" << std::endl;

		delete src1;
	}

	{
		std::cout << "\n===== TEST 3 : Deep copy of Character (copy constructor) =====" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character original("original");
		AMateria *c = src->createMateria("ice");
		original.equip(c);

		Character copy(original);

		Character bob("bob");
		std::cout << "\n              ===== First output of TEST 5  =====" << std::endl;
		original.use(0, bob);
		copy.use(0, bob);

		original.unequip(0);
		original.equip(src->createMateria("cure"));
		std::cout << "\n              ===== Second output of TEST 5  =====" << std::endl;
		original.use(0, bob);
		copy.use(0, bob);
		delete src;
		delete c;//fix the leak of the first test
	}
	return 0;
}

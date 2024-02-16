#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iomanip> //NEEDED ?


static void testSubject(void)
{
	std::cout << "===== TEST FROM SUBJECT =====" << std::endl;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("unknown");
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void	testCharacter(void)
{
	std::cout << "===== TEST CHARACTER =====" << std::endl;
	ICharacter	*hero = new Character("Lucie");
	ICharacter	*enemy = new Character("Correcteur");
	AMateria	*ice = new Ice();

	hero->equip(new Ice());
	hero->equip(ice);
	hero->equip(new Cure());
	hero->equip(new Ice());
	hero->equip(new Ice());
	enemy->equip(new Cure());
	enemy->equip(new Cure());
	enemy->equip(new Cure());

	hero->printInventory();
	enemy->printInventory();

	hero->use(0, *enemy);
	hero->use(1, *enemy);
	hero->use(3, *enemy);
	enemy->use(2, *hero);

	hero->unequip(1);
	hero->printInventory();
	hero->use(1, *enemy);

	hero->equip(new Cure());
	hero->printInventory();
	hero->use(1, *enemy);

	delete hero;
	delete enemy;
	delete ice;
}

static void	testMateriaSource()
{
	std::cout << "===== TEST MATERIA SOURCE =====" << std::endl;
	IMateriaSource	*matSource = new MateriaSource();
	ICharacter		*hero = new Character("Lucie");
	ICharacter		*enemy = new Character("Correcteur");
	
	matSource->learnMateria(new Ice());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());

	hero->printInventory();
	hero->equip(matSource->createMateria("ice"));
	hero->equip(matSource->createMateria("cure"));
	hero->equip(matSource->createMateria("cure"));
	hero->equip(matSource->createMateria("ice"));
	hero->printInventory();
	hero->equip(matSource->createMateria("cure"));
	hero->printInventory();

	hero->use(0, *enemy);
	hero->use(2, *enemy);

	delete matSource;
	delete hero;
	delete enemy;
}

int	main(void)
{
	testSubject();
	testCharacter();
	testMateriaSource();
	return (0);
}
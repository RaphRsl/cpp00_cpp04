#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iomanip>


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
	ICharacter	*student = new Character("Student");
	ICharacter	*blackhole = new Character("Blackhole");
	AMateria	*ice = new Ice();

	student->equip(new Ice());
	student->equip(ice);
	student->equip(new Cure());
	student->equip(new Ice());
	student->equip(new Ice());
	blackhole->equip(new Cure());
	blackhole->equip(new Cure());
	blackhole->equip(new Cure());

	student->printInventory();
	blackhole->printInventory();

	student->use(0, *blackhole);
	student->use(1, *blackhole);
	student->use(3, *blackhole);
	blackhole->use(2, *student);

	student->unequip(1);
	student->printInventory();
	student->use(1, *blackhole);

	student->equip(new Cure());
	student->printInventory();
	student->use(1, *blackhole);

	delete student;
	delete blackhole;
	delete ice;
}

static void	testMateriaSource()
{
	std::cout << "===== TEST MATERIA SOURCE =====" << std::endl;
	IMateriaSource	*matSource = new MateriaSource();
	ICharacter		*student = new Character("Student");
	ICharacter		*blackhole = new Character("Blackhole");
	
	matSource->learnMateria(new Ice());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());

	student->printInventory();
	student->equip(matSource->createMateria("ice"));
	student->equip(matSource->createMateria("cure"));
	student->equip(matSource->createMateria("cure"));
	student->equip(matSource->createMateria("ice"));
	student->printInventory();
	student->equip(matSource->createMateria("cure"));
	student->printInventory();

	student->use(0, *blackhole);
	student->use(2, *blackhole);

	delete matSource;
	delete student;
	delete blackhole;
}

int	main(void)
{
	testSubject();
	testCharacter();
	testMateriaSource();
	return (0);
}
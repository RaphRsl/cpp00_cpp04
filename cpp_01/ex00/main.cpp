#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int	main(void)
{
	std::cout << "_____on the stack_____" << std::endl;
	Zombie	firstZombie_S("firstZombie_S");
	Zombie	secondZombie_S("secondZombie_S");
	Zombie	thirdZombie;

	firstZombie_S.announce();
	secondZombie_S.announce();
	thirdZombie.announce();

	randomChump("randomChumpZombie_S");
	
	std::cout << std::endl;
	std::cout << "_____on the heap_____" << std::endl;

	Zombie	*onlyZombie_H = newZombie("onlyZombie_H");
	onlyZombie_H->announce();
	delete onlyZombie_H;
}
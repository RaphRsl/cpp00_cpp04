#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "Wrong number of arguments.\nExpected format: ./harl [level].\n Possible levels are [DEBUG]/[INFO]/[WARNING]/[ERROR]." << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}
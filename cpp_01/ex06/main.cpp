#include "Harl.hpp"
int	levelDetector(std::string level);

int	main(int ac, char **av)
{
	Harl	harl;
	int		detectedLevel;

	if (ac != 2)
	{
		std::cout << "Wrong number of arguments.\nExpected format: ./harl [level].\n Possible levels are [DEBUG]/[INFO]/[WARNING]/[ERROR]." << std::endl;
		return (1);
	}

	detectedLevel = levelDetector(av[1]);
	// if (detectedLevel == -1)
	// 	std::cout << "Invalid level. Expected level are [DEBUG]/[INFO]/[WARNING]/[ERROR]." << std::endl;
	switch (detectedLevel)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
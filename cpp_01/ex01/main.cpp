#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name );

int	main(int ac, char **av)
{
	Zombie		*horde;
	int			tailleHorde;
	std::string	name;

	if (ac == 1)
	{
		tailleHorde = 5;
		std::cout << "La taille de la horde sera de 5 zombies." << std::endl;
		name = "basicZombie";
		std::cout << "Le nom choisi est 'basicZombie'." << std::endl << std::endl;
	}
	else if (ac == 2)
	{
		tailleHorde = atoi(av[1]);
		if (tailleHorde > 0)
			std::cout << "Vous avez choisi une horde de taille " << tailleHorde << "." << std::endl;
		else
		{
			std::cout << "Taille de la horde impossible. La taille de la horde a été fixée à 5 zombies." << std::endl;
			tailleHorde = 5;
		}
		name = "basicZombie";
		std::cout << "Le nom choisi est 'basicZombie'." << std::endl << std::endl;
	}
	else if (ac == 3)
	{
		tailleHorde = atoi(av[1]);
		if (tailleHorde > 0)
			std::cout << "Vous avez choisi une horde de taille " << tailleHorde << "." << std::endl;
		else
		{
			std::cout << "Taille de la horde impossible. La taille de la horde a été fixée à 5 zombies." << std::endl;
			tailleHorde = 5;
		}
		name = av[2];
		std::cout << "Vous avez choisi comme nom '" << name << "'." << std::endl << std::endl;
	}
	else
	{
		std::cout << "Merci de lancer le programme avec la syntaxe suivante: ./more_brainz[taille de la horde] [nom des zombies]." << std::endl << std::endl;
		return (0);
	}

	horde = zombieHorde(tailleHorde, name);
	for (int i = 0; i < tailleHorde; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	
	std::cout << std::endl << "The horde of " << tailleHorde << " " << name << " has been destroyed." << std::endl;
	
	return (0);
}
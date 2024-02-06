#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);

        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");

        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    std::cout << "\nMy test :\n" << std::endl;

    Weapon axe = Weapon("huge gamer keyboard");
    HumanA gamer("Gamer", axe);

    gamer.attack();
    axe.setType("heavy mouse");
    gamer.attack();

    HumanB player("Player");
    player.setWeapon(axe);
    player.attack();
    axe.setType("big screen");
    player.attack();

	return (0);
}
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

using namespace std;

int	main() {
	std::cout << "\n---- DIAMONDTRAP MAIN ----\n" << std::endl;

	DiamondTrap	DiamondTrapA("DiamondTrapA");
	DiamondTrap	DiamondTrapB("DiamondTrapB");

	std::cout << std::endl;

	std::cout << DiamondTrapA << "\n" << DiamondTrapB << std::endl;

	DiamondTrapA.attack("DiamondTrapB");
	DiamondTrapB.takeDamage(DiamondTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << DiamondTrapA << "\n" << DiamondTrapB << std::endl;

	DiamondTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << DiamondTrapA << "\n" << DiamondTrapB << std::endl;

	DiamondTrapB.whoAmI();
	
	std::cout << std::endl;
	return (0);
}
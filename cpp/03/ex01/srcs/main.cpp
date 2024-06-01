#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

using namespace std;

int	main()
{
	std::cout << "\n---- SCAVTRAP MAIN ----\n" << std::endl;

	ScavTrap	ScavTrapA("ScavTrapA");
	ScavTrap	ScavTrapB("ScavTrapB");

	ScavTrap	ScavTrapC(ScavTrapA);
	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << "\n" << ScavTrapC << std::endl;

	ScavTrapA.attack("ScavTrapB");
	ScavTrapB.takeDamage(ScavTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapB.beRepaired(5);

	std::cout << std::endl;

	ScavTrapB.guardGate();

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;
	
	return (0);
}

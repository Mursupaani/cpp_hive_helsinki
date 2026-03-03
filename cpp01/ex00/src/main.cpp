#include "Zombie.hpp"

int	main(void)
{
	Zombie *z = newZombie("Hank");
	z->announce();
	randomChump("Peter");
	randomChump("Janne");
	randomChump("Tommie");
	delete z;
	return (EXIT_SUCCESS);
}

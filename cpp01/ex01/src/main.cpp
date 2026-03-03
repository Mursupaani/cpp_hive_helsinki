#include "Zombie.hpp"

int	main(void)
{
	int	n = 10;
	Zombie *horde = nullptr;

	try
	{
		horde = zombieHorde(n, "Hank");
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what() << std::endl;;
		return (EXIT_FAILURE);
	}
	for (int i = 0; i < n; ++i)
	{
		std::cout << i << ": ";
		horde[i].announce();
	}
	delete[] horde;
	return (EXIT_SUCCESS);
}

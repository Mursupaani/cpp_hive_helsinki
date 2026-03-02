#include "Harl.hpp"

void	strToLower(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
}

int	main(int ac, char *av[])
{
	Harl	h;
	std::string	input;

	if (ac != 2)
	{
		std::cout << "Please input one: DEBUG / INFO / WARNING / ERROR" << std::endl;
		return(EXIT_FAILURE);
	}
	input = av[1];
	strToLower(input);
	h.complain(input);
	return (EXIT_SUCCESS);
}

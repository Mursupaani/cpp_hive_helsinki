#include <iostream>

void	printArgsInUpperCase(int argc, char *argv[])
{
	std::string	output;

	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j] != 0; ++j)
			output += std::toupper(argv[i][j]);
		if (i < argc - 1)
			output += ' ';
	}
	std::cout << output << '\n';
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOSE *\n";
	else
		printArgsInUpperCase(argc, argv);
	return (0);
}

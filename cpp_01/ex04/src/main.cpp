#include "replace.hpp"

void	replace_substrings(int pos, std::ofstream &outfile, std::string &line, std::string str1, std::string str2)
{
	while (pos != -1)
	{
		outfile << line.substr(0, pos);
		outfile << str2;
		line = line.substr(pos + str1.length());
		pos = line.find(str1);
	}
	outfile << line << std::endl;
}

void	replace(std::ifstream &infile, std::ofstream &outfile, std::string str1, std::string str2)
{
	std::string	line;
	int			pos;

	while (std::getline(infile, line))
	{
		pos = line.find(str1);
		if (pos != -1)
			replace_substrings(pos, outfile, line, str1, str2);
		else
			outfile << line << std::endl;
	}
}

int	main(int ac, char *av[])
{
	std::string	filename;
	std::string	str1;
	std::string	str2;
	std::ifstream infile;
	std::ofstream outfile;

	if (ac != 4)
	{
		std::cout << "Use args: <filename>, <str1>, <str2>" << std::endl;
		return (EXIT_FAILURE);
	}
	filename = av[1];
	str1 = av[2];
	str2 = av[3];
	if (str1.length() == 0)
	{
		std::cout << "Can't search for an empty string" << std::endl;
		return (EXIT_FAILURE);
	}
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cout << "Error opening file " << filename << std::endl;
		return (EXIT_FAILURE);
	}
	outfile.open(filename + ".replace");
	if (!outfile.is_open())
	{
		infile.close();
		std::cout << "Error creating file " << filename + ".replace" << std::endl;
		return (EXIT_FAILURE);
	}
	replace(infile, outfile, str1, str2);
	infile.close();
	outfile.close();
	return (EXIT_SUCCESS);
}

#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

class Replace
{
	public:
		Replace(char *filename, char *str1, char *str2);
		~Replace(void) = default;

		std::string		_filename;
		std::string		_str1;
		std::string		_str2;
		std::ifstream	_infile;
		std::ofstream	_outfile;
};

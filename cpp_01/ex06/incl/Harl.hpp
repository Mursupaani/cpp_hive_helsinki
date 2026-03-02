#pragma once
#include <cstdlib>
#include <string>
#include <iostream>

enum Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NONE
};

class Harl
{
	public:
		void	complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

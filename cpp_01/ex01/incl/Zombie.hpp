#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <exception>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);
	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

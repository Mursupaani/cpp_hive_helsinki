#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void) = default;

		void	attack(void);
	private:
		std::string	_name;
		Weapon		&_weapon;
};

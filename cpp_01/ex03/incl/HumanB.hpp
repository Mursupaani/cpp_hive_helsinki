#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB(void) = default;

		void	setWeapon(Weapon &weapon);
		void	attack(void);
	private:
		std::string	_name;
		Weapon		*_weapon;
};

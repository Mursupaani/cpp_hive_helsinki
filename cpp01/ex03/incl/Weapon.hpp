#pragma once
#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon() = default;

		const std::string	&getType(void) const;
		void				setType(std::string type);
	private:
		std::string	_type;
};

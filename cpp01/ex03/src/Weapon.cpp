#include "Weapon.hpp"
#include <string>

Weapon::Weapon() : _type("hands")
{}

Weapon::Weapon(std::string type) : _type(type)
{}

const std::string	&Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

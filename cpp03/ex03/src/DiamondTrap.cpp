/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:42:08 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/18 13:34:23 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	_name = ClapTrap::_name;
	ClapTrap::_name += "_clap_name";
	_health = FragTrap::_health;
	_maxHealth = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	_className = "DiamondTrap";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "Parametrized DiamondTrap constructor called" << std::endl;
	_name = name;
	_health = FragTrap::_health;
	_maxHealth = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	_className = "DiamondTrap";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name = other._name;
	_health = other._health;
	_health = other._maxHealth;
	_energy = other._energy;
	_damage = other._damage;
	_className = other._className;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_health = other._health;
	_health = other._maxHealth;
	_energy = other._energy;
	_damage = other._damage;
	_className = other._className;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << " therefore I am a " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:42:08 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/17 18:44:05 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Scav Doe")
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	_health = 100;
	_maxHealth = 100;
	_energy = 50;
	_damage = 20;
	_className = "ScavTrap";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametrized ScavTrap constructor called" << std::endl;
	_health = 100;
	_maxHealth = 100;
	_energy = 50;
	_damage = 20;
	_className = "ScavTrap";
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_name = other._name;
	_health = other._health;
	_health = other._maxHealth;
	_energy = other._energy;
	_damage = other._damage;
	_className = other._className;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
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

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_health == 0)
	{
		std::cout << _className << " " << _name
			<< " tried to attack but they are dead!" << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << _className << " " << _name
			<< " tried to attack but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << _className << " " << _name << " attacks " << target
		<< ", causing " << _damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_health == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " tried to go into Gate keeper mode but they are dead!" << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " tried to go into Gate keeper mode but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "ScavTrap " << _name << " is in Gate keeper mode!" << std::endl;
}

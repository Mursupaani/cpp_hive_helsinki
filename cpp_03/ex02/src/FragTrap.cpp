/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:42:08 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/18 12:20:08 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Frag Doe")
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	_health = 100;
	_maxHealth = 100;
	_energy = 100;
	_damage = 30;
	_className = "FragTrap";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametrized FragTrap constructor called" << std::endl;
	_health = 100;
	_maxHealth = 100;
	_energy = 100;
	_damage = 30;
	_className = "FragTrap";
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_name = other._name;
	_health = other._health;
	_health = other._maxHealth;
	_energy = other._energy;
	_damage = other._damage;
	_className = other._className;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
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

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
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

void FragTrap::highFiveGuys(void)
{
	if (_health == 0)
	{
		std::cout << "FragTrap " << _name
			<< " tried to high five guys but they are dead!" << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "FragTrap " << _name
			<< " tried to high five guys but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "FragTrap " << _name << " gives a high five to guys!" << std::endl;
}

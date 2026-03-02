/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:47:55 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/17 18:06:07 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("John Doe"), _health(10), _energy(10), _damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "Parametrized constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = other._name;
	_health = other._health;
	_energy = other._energy;
	_damage = other._damage;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_health = other._health;
	_energy = other._energy;
	_damage = other._damage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_health == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " tried to attack but they are dead!" << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " tried to attack but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	long long tempHP = static_cast<long long>(_health) - amount;
	if (tempHP < 0)
		_health = 0;
	else
		_health -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " damage causing them to drop to " << _health << " health!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " tried to repair but they are dead!" << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " tried to repair but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	long long tempHP = static_cast<long long>(_health) + amount;
	std::cout << "ClapTrap " << _name << " is repaired by " << amount << "!";
	if (tempHP > 10)
	{
		_health = 10;
		std::cout << " Too bad extra repair is wasted...";
	}
	else
		_health += amount;
	std::cout << " They now have " << _health << " health!" << std::endl;
}

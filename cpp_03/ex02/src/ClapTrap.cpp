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

ClapTrap::ClapTrap(void) : _name("Clap Doe"), _health(10), _maxHealth(10),
	_energy(10), _damage(0), _className("ClapTrap")
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _maxHealth(10),
	_energy(10), _damage(0), _className("ClapTrap")
{
	std::cout << "Parametrized ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = other._name;
	_health = other._health;
	_maxHealth = other._maxHealth;
	_energy = other._energy;
	_damage = other._damage;
	_className = other._className;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_health = other._health;
	_maxHealth = other._maxHealth;
	_energy = other._energy;
	_damage = other._damage;
	_className = other._className;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	long long tempHP = static_cast<long long>(_health) - amount;
	if (tempHP <= 0)
		_health = 0;
	else
		_health -= amount;
	std::cout << _className << " " << _name << " takes " << amount
		<< " damage causing them to drop to " << _health << " health!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << _className << " " << _name
			<< " tried to repair but they are dead!" << std::endl;
		return ;
	}
	if (_energy <= 0)
	{
		std::cout << _className << " " << _name
			<< " tried to repair but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	long long tempHP = static_cast<long long>(_health) + amount;
	std::cout << _className << " " << _name << " is repaired by " << amount << "!";
	if (tempHP > _maxHealth)
	{
		_health = _maxHealth;
		std::cout << " Too bad extra repair is wasted...";
	}
	else
		_health = tempHP;
	std::cout << " They now have " << _health << " health!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:38:24 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/21 15:38:30 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <string>

Character::Character(void) : _curInvCount(0), _curUnequipCount(0)
{
	_name = "John Doe";
	for (unsigned int i = 0; i < _invMax; ++i)
		_inventory[i] = nullptr;
	for (unsigned int i = 0; i < _unequippedMax; ++i)
		_unequipped[i] = nullptr;
}

Character::Character(const std::string name) : Character()
{
	_name = name;
}

Character::Character(const Character &other) : _curInvCount(other._curInvCount), _curUnequipCount(other._curUnequipCount)
{
	_name = other._name;
	for (unsigned int i = 0; i < _unequippedMax; ++i)
		_unequipped[i] = nullptr;
	for (unsigned int i = 0; i < _invMax; ++i)
		_inventory[i] = nullptr;
	for (unsigned int i = 0; i < _invMax; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
}

Character::~Character(void)
{
	for (unsigned int i = 0; i < _invMax; ++i)
	{
		if (_inventory[i])
			delete (_inventory[i]);
	}
	for (unsigned int i = 0; i < _unequippedMax; ++i)
	{
		if (_unequipped[i])
			delete (_unequipped[i]);
	}
}

void Character::equip(AMateria *M)
{
	if (_curInvCount >= _invMax)
		std::cout << "Inventory is already full\n";
	else
	{
		for (unsigned int i = 0; i < _invMax; ++i)
		{
			if (_inventory[i] == nullptr)
			{
				_inventory[i] = M;
				++_curInvCount;
				return ;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > static_cast<int>(_invMax))
		std::cout << "Index outside of range\n";
	if (_curUnequipCount >= _unequippedMax)
		std::cout << "You came to realize that you have unequipped too many things in your life" << std::endl;
	else if (_inventory[idx])
	{
		_unequipped[_curUnequipCount] = _inventory[idx];
		++_curUnequipCount;
		_inventory[idx] = nullptr;
		--_curInvCount;
	}
	else
		std::cout << "The slot is already empty\n";
}

std::string const &Character::getName(void) const
{
	return (_name);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= static_cast<int>(_invMax))
		std::cout << "Index outside of range" << "\n";
	else if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Nothing equipped in slot " << idx << "\n";
}

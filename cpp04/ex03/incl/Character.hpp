/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:37:39 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/21 15:39:33 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	static const unsigned int _invMax = 4;
	static const unsigned int _unequippedMax = 100;
	AMateria *_inventory[_invMax];
	unsigned int _curInvCount;
	AMateria *_unequipped[_unequippedMax];
	unsigned int _curUnequipCount;
public:
	Character(void);
	Character(const std::string name);
	Character(const Character &other);
	~Character();
	std::string const & getName() const override;
	void equip(AMateria* m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;
};

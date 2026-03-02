/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:18:48 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/21 17:42:05 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	AMateria* clone;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	clone = tmp->clone();

	std::cout << "Original: " << tmp->getType() << std::endl;
	std::cout << "Clone: " << clone->getType() << std::endl;
	delete clone;
	tmp = src->createMateria("cure");
	clone = tmp->clone();
	std::cout << "Original: " << tmp->getType() << std::endl;
	std::cout << "Clone: " << clone->getType() << std::endl;
	std::cout << "\n";
	delete clone;
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	ICharacter* me_clone = new Character(*dynamic_cast<Character *>(me));
	delete me;
	me_clone->use(0, *bob);
	me_clone->use(1, *bob);
	std::cout << "\n";
	me_clone->unequip(0);
	me_clone->use(0, *bob);
	me_clone->use(-1, *bob);
	me_clone->use(4, *bob);
	tmp = src->createMateria("cure");
	me_clone->equip(tmp);
	me_clone->use(0, *bob);
	std::cout << "\n";
	me_clone->unequip(0);
	me_clone->unequip(0);
	me_clone->unequip(1);
	me_clone->unequip(1);

	delete bob;
	delete me_clone;
	delete src;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:48:09 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/18 18:50:47 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

int main(void)
{
	std::cout << '\n';
	const Animal* meta = new Animal();
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	delete meta;
	std::cout << '\n';
	const Animal* j = new Dog();
	std::cout << j->getType() << ": ";
	j->makeSound();
	delete j;
	std::cout << '\n';
	const Animal* i = new Cat();
	std::cout << i->getType() << ": ";
	i->makeSound();
	delete i;
	std::cout << '\n';
	const WrongAnimal* wrong = new WrongAnimal();
	std::cout << wrong->getType() << ": ";
	wrong->makeSound();
	delete wrong;
	std::cout << '\n';
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << ": ";
	wrongCat->makeSound();
	delete wrongCat;
	return (EXIT_SUCCESS);
}

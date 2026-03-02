/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:43:01 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/19 11:45:17 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
	_brain = new Brain;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_type = other._type;
	*_brain = *other._brain;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound(void) const
{
	std::cout << "'Woof'" << std::endl;
}

void Dog::addIdea(const std::string idea)
{
	if (!_brain)
		return ;
	_brain->setIdea(idea);
}

std::string Dog::getIdea(const unsigned int i) const
{
	return (_brain->getIdea(i));
}

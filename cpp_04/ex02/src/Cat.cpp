/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:43:01 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/19 11:45:35 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
	_brain = new Brain;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_type = other._type;
	*_brain = *other._brain;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound(void) const
{
	std::cout << "'Meow'" << std::endl;
}

void Cat::addIdea(const std::string idea)
{
	if (!_brain)
		return ;
	_brain->setIdea(idea);
}

std::string Cat::getIdea(const unsigned int i) const
{
	return (_brain->getIdea(i));
}

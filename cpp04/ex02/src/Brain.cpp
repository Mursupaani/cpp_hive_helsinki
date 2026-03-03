/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:30:13 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/19 13:12:50 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	_currentIdea = 0;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = "Food...";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	_currentIdea = other._currentIdea;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_currentIdea = other._currentIdea;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(const int i)
{
	if (i < 0 || i >= 100)
		throw std::out_of_range("Outside of range");
	return (_ideas[i]);
}

void Brain::setIdea(const std::string idea)
{
	_ideas[_currentIdea] = idea;
	++_currentIdea %= 100;
}

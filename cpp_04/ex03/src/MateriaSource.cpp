/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:16:32 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/21 18:18:38 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _materiaCount(0)
{
	for (unsigned int i = 0; i < _maxMaterias; ++i)
		_materias[i] = nullptr;
}

MateriaSource::~MateriaSource(void)
{
	for (unsigned int i = 0; i < _maxMaterias; ++i)
		delete _materias[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (_materiaCount > _maxMaterias)
		throw std::runtime_error("MateriaSource has reached max count of Materias (100)\n");
	if (m->getType() == "ice")
	{
		_materias[_materiaCount] = m;
		++_materiaCount;
	}
	else if (m->getType() == "cure")
	{
		_materias[_materiaCount] = m;
		++_materiaCount;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	else
		throw std::runtime_error("Unknown materia type");
}

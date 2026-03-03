/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:42:32 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/21 18:17:40 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <stdexcept>
#include <string>

class MateriaSource : public IMateriaSource
{
private:
	static const unsigned int _maxMaterias = 4;
	AMateria *_materias[_maxMaterias];
	unsigned int _materiaCount;
public:
	MateriaSource(void);
	~MateriaSource(void);
	void learnMateria(AMateria* m) override;
	AMateria* createMateria(std::string const & type) override;
};

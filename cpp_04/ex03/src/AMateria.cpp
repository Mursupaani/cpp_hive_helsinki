/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:25:40 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/21 15:25:46 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{}

const std::string &AMateria::getType(void) const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << _type << "used on " << target.getName() << "\n";
}

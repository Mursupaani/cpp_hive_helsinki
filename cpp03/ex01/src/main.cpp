/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:48:09 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/17 18:07:44 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <climits>

int main(void)
{
	{
		ClapTrap clap {"Sir Clappington"};
		clap.attack("Pena");
		clap.takeDamage(9);
		clap.beRepaired(2);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.attack("Pena");
	}
	std::cout << std::endl;
	{
		ScavTrap clap{"Pekka"};
		clap.guardGate();
		clap.attack("Sir Slappington");
		clap.beRepaired(INT_MAX);
		clap.takeDamage(5);
		clap.takeDamage(15);
		clap.beRepaired(15);
		for (int i = 0; i < 46; ++i)
		{
			std::cout << i << ": ";
			clap.attack("Target");
		}
		clap.attack("Sir Clappington");
		clap.guardGate();
	}
	std::cout << std::endl;
	{
		ScavTrap scav;
		scav.guardGate();
	}
	return (EXIT_SUCCESS);
}

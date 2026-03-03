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
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
		ClapTrap clap;
		clap.attack("Sir Clappington");
		clap.takeDamage(5);
		clap.beRepaired(1);
		clap.attack("Sir Clappington");
		clap.takeDamage(15);
		clap.beRepaired(15);
		clap.attack("Sir Clappington");
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
		FragTrap frag{"Simo"};
		frag.attack("Sir Slappington");
		frag.highFiveGuys();
		frag.beRepaired(INT_MAX);
		frag.takeDamage(5);
		frag.takeDamage(15);
		frag.beRepaired(15);
		for (int i = 0; i < 100; ++i)
		{
			if (i % 2 == 0)
			{
				std::cout << i << ": ";
				frag.attack("Target");
			}
			else
			{
				std::cout << i << ": ";
				frag.highFiveGuys();
			}
		}
	}
	std::cout << std::endl;
	{
		DiamondTrap diamond{"Teppo"};
		diamond.highFiveGuys();
		diamond.guardGate();
		diamond.whoAmI();
		diamond.attack("Hobo");
	}
		std::cout << std::endl;
	{
		DiamondTrap diamond2;
		diamond2.highFiveGuys();
		diamond2.guardGate();
		diamond2.whoAmI();
		diamond2.attack("Hobo");

	}
	return (EXIT_SUCCESS);
}

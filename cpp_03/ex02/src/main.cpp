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
#include "FragTrap.hpp"
#include <climits>

int main(void)
{
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
		FragTrap test;
		test.highFiveGuys();
	}
	return (EXIT_SUCCESS);
}

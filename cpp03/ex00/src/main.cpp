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

int main(void)
{
	std::cout << std::endl;
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
	return (EXIT_SUCCESS);
}

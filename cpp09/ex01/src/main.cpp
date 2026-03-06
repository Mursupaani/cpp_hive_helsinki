/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:56:41 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/23 17:12:21 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2)
		return (1);
	std::string input = av[1];
	try {
		RPN::calculate(input);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

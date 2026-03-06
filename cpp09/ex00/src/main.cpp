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

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "ERROR: Please input argument <input_data>" << std::endl;
		return (1);
	}
	try {
		std::string input = av[1];
		BitcoinExchange::loadDataBase();
		BitcoinExchange::parseInputFile(input);
	} catch (std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return (1);
	}
}

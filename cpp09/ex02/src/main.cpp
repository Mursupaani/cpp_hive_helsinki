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

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac == 1)
		return (1);
	try {
		PmergeMe::vectorSort(ac, av);
		std::cout << "Vector took " << PmergeMe::getVDuration().count() * 1000
				  << "ms" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

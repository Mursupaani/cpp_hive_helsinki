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

#include <deque>
#include <exception>
#include <vector>

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac == 1) {
		std::cerr << "Usage: ./PmergeMe <positive int>..." << std::endl;
		return (1);
	}
	try {
		PmergeMe::validateInputNumbers(ac, av);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	try {
		std::vector<std::vector<int>> sortedVec = PmergeMe::vectorSort(ac, av);
		std::deque<std::deque<int>>	  sortedDeq = PmergeMe::dequeSort(ac, av);
		PmergeMe::printResults(ac, av, sortedDeq);
		// PmergeMe::printResults(sortedVec);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
}

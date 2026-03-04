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

#include <array>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

#include "easyfind.hpp"

int main(void) {
	{
		std::cout << "TEST 1 (std::array):\n";
		std::array<int, 5> array = {0, 1, 2, 3, 4};
		std::cout << easyfind(array, 0) << std::endl;
		try {
			std::cout << "\nLooking for 3\n";
			std::cout << easyfind(array, 3) << " found" << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 2 (std::array):\n";
		std::array<int, 5> array = {0, 1, 2, 3, 4};
		std::cout << easyfind(array, 0) << std::endl;
		try {
			std::cout << "\nLooking for 5\n";
			std::cout << easyfind(array, 5) << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 3 (std::vector):\n";
		std::vector<int> vector = {0, 1, 2, 3, 4};
		std::cout << easyfind(vector, 1) << std::endl;
		try {
			std::cout << "\nLooking for -1\n";
			std::cout << easyfind(vector, -1) << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 4 (std::list):\n";
		std::list<int> vector = {0, 1, 2, 3, 4};
		std::cout << "Looking for 2\n";
		std::cout << easyfind(vector, 2) << std::endl;
		try {
			std::cout << "\nLooking for 100\n";
			std::cout << easyfind(vector, 100) << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 5 (std::array):\n";
		std::array<int, 5> array = {0, 1, 2, 3, 4};
		int				  &x = easyfind(array, 0);
		x = 10;
		for (auto val : array)
			std::cout << val << std::endl;
		try {
			std::cout << "\nLooking for 10\n";
			std::cout << easyfind(array, 10) << " found" << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 6 (const std::array):\n";
		const std::array<int, 5> array = {0, 1, 2, 3, 4};
		// int &x = easyfind(array, 0);
		// x = 10;
		for (auto val : array)
			std::cout << val << std::endl;
		try {
			std::cout << "\nLooking for 4\n";
			std::cout << easyfind(array, 4) << " found" << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "____________________\n\n";
	}
}

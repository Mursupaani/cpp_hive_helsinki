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

#include <cctype>
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>

#include "iter.hpp"

class Data {
	private:
		size_t _x;

	public:
		Data(void) = delete;
		Data(size_t x) : _x(x) {}
		~Data(void) = default;
		int getX(void) const {
			return (_x);
		}
};

std::ostream &operator<<(std::ostream &os, Data &data) {
	os << data.getX();
	return (os);
}

template <typename T>
void print(T elem) {
	std::cout << elem << std::endl;
}

template <typename T>
void incrementAndPrint(T elem) {
	++elem;
	std::cout << elem << std::endl;
}

int main(void) {
	{
		int array[5]{0, 1, 2, 3, 4};
		std::cout << "TEST 1:\n";
		iter(array, 5, print<int>);
		std::cout << "____________________\n\n";
		std::cout << "TEST 2:\n";
		iter(array, 5, incrementAndPrint<int>);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 3:\n";
		std::string array[5]{"test 1", "test 2", "test 3", "test 4", "test 5"};
		iter(array, 5, print<std::string>);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 4:\n";
		Data array[3]{Data(123), Data(456), Data(789)};
		iter(array, 3, print<Data>);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 5:\n";
		char array[5]{'a', 'b', 'c', 'd', 'e'};
		std::cout << "Original char[]:\n";
		for (int i = 0; i < 5; ++i) {
			std::cout << array[i] << "\n";
		}
		iter(array, 5, [](char &c) { c = toupper(c); });
		std::cout << "\nModified char[]:\n";
		for (int i = 0; i < 5; ++i) {
			std::cout << array[i] << "\n";
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 6:\n";
		std::cout << "Trying to use a null pointer to array.\n";
		int *array = nullptr;
		iter(array, 5, print<int>);
		std::cout << "____________________\n\n";
	}
}

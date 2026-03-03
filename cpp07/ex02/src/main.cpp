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
#include <climits>
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

#include "Array.hpp"

int main(void) {
	{
		std::cout << "TEST 1:\n";
		Array<int> array(5);
		for (unsigned int i = 0; i < array.size(); ++i)
			array[i] = i;

		std::cout << "Array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 2:\n";
		Array<int> array(10);
		std::cout << "Array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 3:\n";
		Array<std::string> array(7);
		std::cout << "Array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			array[i] = "string " + std::to_string(i);

		for (unsigned int i = 0; i < 5; ++i)
			std::cout << array[i] << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 4:\n";
		Array<std::string> array(3);
		std::cout << "Array size: " << array.size() << "\n";
		for (unsigned i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 5:\n";
		Array<int> array(5);
		std::cout << "Array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			array[i] = i;
		for (unsigned i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;

		try {
			std::cout << "\nTrying to access array[5]\n";
			array[5];
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "____________________\n\n";
		std::cout << "TEST 6:\n";
		Array<int> array(5);
		std::cout << "Array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			array[i] = i;
		for (unsigned i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		try {
			std::cout << "\nTrying to access array[-1]\n";
			array[-1];
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "____________________\n\n";
		std::cout << "TEST 7:\n";
		Array<int> array(5);
		std::cout << "Original array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			array[i] = i;
		Array<int> array_copy(array);
		std::cout << "Copied array size: " << array_copy.size() << "\n\n";
		std::cout << "Original array data: \n";
		for (unsigned i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;

		std::cout << "\nCopied array data:\n";
		for (unsigned i = 0; i < array_copy.size(); ++i)
			std::cout << array_copy[i] << std::endl;

		std::cout << "\nOriginal array incremented data:\n";
		for (unsigned i = 0; i < array.size(); ++i)
			++array[i];
		for (unsigned i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		std::cout << "\nCopied array data:\n";
		for (unsigned i = 0; i < array_copy.size(); ++i)
			std::cout << array_copy[i] << std::endl;

		std::cout << "____________________\n\n";
	}
	{
		std::cout << "____________________\n\n";
		std::cout << "TEST 8:\n";
		Array<int> array(5);
		std::cout << "Original array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			array[i] = i;
		Array<int> array_copy;
		std::cout << "\nArray_copy size before copy: " << array_copy.size()
				  << "\n\n";
		array_copy = array;
		std::cout << "Copied array size: " << array_copy.size() << "\n\n";
		std::cout << "Original array data: \n";
		for (unsigned i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;

		std::cout << "\nCopied array data:\n";
		for (unsigned i = 0; i < array_copy.size(); ++i)
			std::cout << array_copy[i] << std::endl;

		std::cout << "\nOriginal array incremented data:\n";
		for (unsigned i = 0; i < array.size(); ++i)
			++array[i];
		for (unsigned i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		std::cout << "\nCopied array data:\n";
		for (unsigned i = 0; i < array_copy.size(); ++i)
			std::cout << array_copy[i] << std::endl;

		std::cout << "____________________\n\n";
	}

	{
		std::cout << "TEST 9:\n";
		Array<int> array = {0, 1, 2, 3, 4, 5};

		std::cout << "Const array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		array[0] = 5;
		std::cout << "\nChange array[0] = 5\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 10:\n";
		const Array<int> array = {0, 1, 2, 3, 4, 5};

		std::cout << "Const array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		// array[0] = 5;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 11:\n";
		const Array<std::string> array = {"test 1", "test 2", "test 3",
										  "test 4"};

		std::cout << "Array size: " << array.size() << "\n";
		for (unsigned int i = 0; i < array.size(); ++i)
			std::cout << array[i] << std::endl;
		// array[0] = "test";
		std::cout << "____________________\n\n";
	}
}

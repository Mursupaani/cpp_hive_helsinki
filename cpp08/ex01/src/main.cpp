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
#include <iostream>
#include <numeric>
#include <stdexcept>

#include "Span.hpp"

int main(void) {
	{
		std::cout << "TEST 1:\n\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "____________________\n\n" << std::endl;
	}
	{
		std::cout << "TEST 2:\n\n";
		std::vector<int> vec = {0, 1, 2, 3, 4};
		Span			 sp = Span(vec.size());
		sp.fillSpan(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "____________________\n\n" << std::endl;
	}
	{
		std::cout << "TEST 3:\n\n";
		std::vector<int> vec(10000);
		std::iota(vec.begin(), vec.end(), 0);
		Span sp = Span(vec.size());
		sp.fillSpan(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "____________________\n\n" << std::endl;
	}
	{
		std::cout << "TEST 4:\n\n";
		std::array<int, 10000> array;
		std::iota(array.begin(), array.end(), 0);
		Span sp = Span(array.size());
		sp.fillSpan(array.begin(), array.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "____________________\n\n" << std::endl;
	}
	{
		std::cout << "TEST 5:\n\n";
		Span sp = Span(20000);
		sp.fillSpanRandom(INT_MIN, INT_MAX);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "____________________\n\n" << std::endl;
	}
	{
		std::cout << "TEST 6:\n\n";
		Span copy2(10);
		{
			Span sp(10);
			sp.fillSpanRandom(0, 10);
			std::cout << "  Original:\n";
			std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
			std::cout << "  __________________\n\n" << std::endl;
			{
				Span copy1(sp);

				std::cout << "  Copy 1:\n";
				std::cout << "  Shortest span: " << copy1.shortestSpan()
						  << std::endl;
				std::cout << "  Longest span: " << copy1.longestSpan()
						  << std::endl;
				std::cout << "  __________________\n\n" << std::endl;
				copy2 = copy1;
			}
		}
		std::cout << "  Copy 2:\n";
		std::cout << "  Shortest span: " << copy2.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << copy2.longestSpan() << std::endl;
		std::cout << "______________________\n\n" << std::endl;
	}
	{
		std::cout << "TEST 7:\n\n";
		Span sp = Span(1);
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << "\n";
		}
		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << "____________________\n\n" << std::endl;
	}
	{
		std::cout << "TEST 8:\n\n";
		Span sp = Span(0);
		try {
			sp.addNumber(0);
		} catch (std::runtime_error &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << "____________________\n\n" << std::endl;
	}
	{
		std::cout << "TEST 9:\n\n";
		Span sp = Span(5);
		sp.addNumber(0);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		try {
			sp.addNumber(0);
		} catch (std::runtime_error &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << "____________________\n" << std::endl;
	}
	return 0;
}

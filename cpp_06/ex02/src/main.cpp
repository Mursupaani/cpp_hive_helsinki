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

#include <iostream>

#include "identify.hpp"

int main(void) {
	{
		std::cout << "TEST 1 with Base pointers\n\n";
		for (int i = 0; i < 10; ++i) {
			Base *base = generate();
			std::cout << i + 1 << ": ";
			identify(base);
			delete base;
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 2 with Base reference\n\n";
		for (int i = 0; i < 10; ++i) {
			Base *base = generate();
			std::cout << i + 1 << ": ";
			identify(*base);
			delete base;
		}
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 3 with explicit Base pointers\n\n";
		A *a = new A;
		B *b = new B;
		C *c = new C;
		identify(a);
		identify(b);
		identify(c);
		delete a;
		delete b;
		delete c;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 4 with explicit Base reference\n\n";
		A a;
		B b;
		C c;
		identify(a);
		identify(b);
		identify(c);
		std::cout << "____________________\n\n";
	}
}

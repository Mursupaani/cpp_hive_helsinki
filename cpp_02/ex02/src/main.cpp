/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:26:20 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/10 10:26:22 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	{
		Fixed a(3);
		Fixed b(4);
		Fixed c = a;

		std::cout << a << " > " << b << " : " << (a > b) << std::endl;
		std::cout << a << " < " << b << " : " << (a < b) << std::endl;
		std::cout << a << " >= " << b << " : " << (a >= b) << std::endl;
		std::cout << a << " <= " << b << " : " << (a <= b) << std::endl;
		std::cout << a << " == " << b << " : " << (a == b) << std::endl;
		std::cout << a << " != " << b << " : " << (a != b) << std::endl;
		std::cout << a << " > " << c << " : " << (a > c) << std::endl;
		std::cout << a << " < " << c << " : " << (a < c) << std::endl;
		std::cout << a << " >= " << c << " : " << (a >= c) << std::endl;
		std::cout << a << " <= " << c << " : " << (a <= c) << std::endl;
		std::cout << a << " == " << c << " : " << (a == c) << std::endl;
		std::cout << a << " != " << c << " : " << (a != c) << std::endl;
		std::cout << a << " + " << b << " = " << (a + b) << std::endl;
		std::cout << a << " - " << b << " = "  << (a - b) << std::endl;
		std::cout << a << " * " << b << " = "  << (a * b) << std::endl;
		std::cout << a << " / " << b << " = "  << (a / b) << std::endl;
	}
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		Fixed c = 10;
		std::cout << "a :\t" << a << std::endl;
		std::cout << "++a :\t" << ++a << std::endl;
		std::cout << "a :\t" << a << std::endl;
		std::cout << "a++ :\t" << a++ << std::endl;
		std::cout << "a :\t" << a << std::endl;
		std::cout << "--a :\t" << --a << std::endl;
		std::cout << "a :\t" << a << std::endl;
		std::cout << "a-- :\t" << a-- << std::endl;
		std::cout << "a :\t" << a << std::endl;
		std::cout << "b :\t" << b << std::endl;
		std::cout << "c :\t" << c << std::endl;
		std::cout << "max(a, b) :   " << Fixed::max(a, b) << std::endl;
		std::cout << "min(a, b) :   " << Fixed::min(a, b) << std::endl;
		std::cout << "min(a, c) :   " << Fixed::min(a, c) << std::endl;
		std::cout << "min(a, c)++ : " << Fixed::min(a, c)++ << std::endl;
		std::cout << "min(a, c) :   " << Fixed::min(a, c) << std::endl;
		std::cout << "++min(a, c) : " << ++Fixed::min(a, c) << std::endl;
		std::cout << "min(a, c) :   " << Fixed::min(a, c) << std::endl;
		std::cout << "max(a, c)-- : " << Fixed::max(a, c)-- << std::endl;
		std::cout << "max(a, c) :   " << Fixed::max(a, c) << std::endl;
		std::cout << "--max(a, c) : " << --Fixed::max(a, c) << std::endl;
		std::cout << "max(a, c) :   " << Fixed::max(a, c) << std::endl;
	}
	// Const max and min test
	// {
	// 	Fixed const a;
	// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// 	std::cout << "max(a, b) :   " << ++Fixed::max(a, b) << std::endl;
	// 	std::cout << "max(a, b) :   " << Fixed::max(a, b)++ << std::endl;
	// 	std::cout << "max(a, b) :   " << ++Fixed::min(a, b) << std::endl;
	// 	std::cout << "max(a, b) :   " << Fixed::min(a, b)++ << std::endl;
	// 	std::cout << "max(a, b) :   " << --Fixed::max(a, b) << std::endl;
	// 	std::cout << "max(a, b) :   " << Fixed::max(a, b)-- << std::endl;
	// 	std::cout << "max(a, b) :   " << --Fixed::min(a, b) << std::endl;
	// 	std::cout << "max(a, b) :   " << Fixed::min(a, b)-- << std::endl;
	// }
	return (EXIT_SUCCESS);
}

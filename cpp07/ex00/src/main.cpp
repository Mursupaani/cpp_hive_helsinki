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

#include "whatever.hpp"

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
		bool operator==(const Data &other) const {
			if (_x == other._x)
				return true;
			return false;
		}
		bool operator!=(const Data &other) const {
			if (_x != other._x)
				return true;
			return false;
		}
		bool operator<(const Data &other) const {
			if (_x < other._x)
				return true;
			return false;
		}
		bool operator>(const Data &other) const {
			if (_x > other._x)
				return true;
			return false;
		}
		bool operator<=(const Data &other) const {
			if (_x <= other._x)
				return true;
			return false;
		}
		bool operator>=(const Data &other) const {
			if (_x >= other._x)
				return true;
			return false;
		}
};

std::ostream &operator<<(std::ostream &os, Data &data) {
	os << data.getX();
	return (os);
}

int main(void) {
	{
		std::cout << "TEST IN THE SUBJECT:\n";
		int a = 2;
		int b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 1:\n";
		int a = 3;
		int b = 3;
		std::cout << "&a = " << &a << std::endl;
		std::cout << "&b = " << &b << std::endl;
		std::cout << "min( a, b ) = " << &::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << &max(a, b) << std::endl;
	}
	{
		std::cout << "TEST 2:\n";
		std::string c = "chaine2";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "&c = " << &c << std::endl;
		std::cout << "&d = " << &d << std::endl;
		std::cout << "min( c, d ) = " << &::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << &::max(c, d) << std::endl;
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 3:\n";
		Data a(5);
		Data b(6);
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::cout << "____________________\n\n";
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:26:20 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/17 15:19:41 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

int	main(void)
{
	Point a{0.0f, 0.0f};
	Point b{5.0f, 0.0f};
	Point c{0.0f, 5.0f};
	Point point0{1.0f, 1.0f};
	Point point1{0.01, 0.01f};
	Point point2{4.9f, 0.01f};
	Point point3{0.0f, 4.99f};
	Point point4{0.0f, -0.01f};
	Point point5{-0.01, 0.01f};
	Point point6{4.99f, -0.01f};
	Point point7{-0.01f, 4.99f};

	std::cout << "Point a: \n\tx: " << a.getX() << "\n\ty: " << a.getY() << std::endl;
	std::cout << "Point b: \n\tx: " << b.getX() << "\n\ty: " << b.getY() << std::endl;
	std::cout << "Point c: \n\tx: " << c.getX() << "\n\ty: " << c.getY() << std::endl;
	std::cout << "\nPoint point0: \n\tx: " << point0.getX() << "\n\ty: " << point0.getY() << std::endl;
	std::cout << "\tIs inside: " << bsp(a, b, c, point0) << std::endl;
	std::cout << "\nPoint point1: \n\tx: " << point1.getX() << "\n\ty: " << point1.getY() << std::endl;
	std::cout << "\tIs inside: " << bsp(a, b, c, point1) << std::endl;
	std::cout << "\nPoint point2: \n\tx: " << point2.getX() << "\n\ty: " << point2.getY() << std::endl;
	std::cout << "\tIs inside: " << bsp(a, b, c, point2) << std::endl;
	std::cout << "\nPoint point3: \n\tx: " << point3.getX() << "\n\ty: " << point3.getY() << std::endl;
	std::cout << "\tIs inside: " << bsp(a, b, c, point3) << std::endl;
	std::cout << "\nPoint point4: \n\tx: " << point4.getX() << "\n\ty: " << point4.getY() << std::endl;
	std::cout << "\tIs inside: " << bsp(a, b, c, point4) << std::endl;
	std::cout << "\nPoint point5: \n\tx: " << point5.getX() << "\n\ty: " << point5.getY() << std::endl;
	std::cout << "\tIs inside: " << bsp(a, b, c, point5) << std::endl;
	std::cout << "\nPoint point6: \n\tx: " << point6.getX() << "\n\ty: " << point6.getY() << std::endl;
	std::cout << "\tIs inside: " << bsp(a, b, c, point6) << std::endl;
	std::cout << "\nPoint point7: \n\tx: " << point7.getX() << "\n\ty: " << point7.getY() << std::endl;
	std::cout << "\tIs inside: " << bsp(a, b, c, point7) << std::endl;
	return (EXIT_SUCCESS);
}

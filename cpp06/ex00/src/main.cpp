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

#include <limits>

#include "ScalarConverter.hpp"

static void runTests(void) {
	std::string literal;
	{
		std::cout << "TEST 1:\n";
		literal = "32";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 2:\n";
		literal = "127";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 3:\n";
		literal = "0";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 4:\n";
		literal = "255";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 5:\n";
		literal = "-1";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 6:\n";
		literal = "256";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 7:\n";
		literal = "2147483647";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 8:\n";
		literal = "-2147483648";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 9:\n";
		literal = "2147483648";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 10:\n";
		literal = "-2147483649";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 11:\n";
		literal = "-inff";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 12:\n";
		literal = "+inff";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 13:\n";
		literal = "nanf";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 14:\n";
		literal = "-inf";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 15:\n";
		literal = "+inf";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 16:\n";
		literal = "nan";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 17:\n";
		literal =
			"179769313486231570814527423731704356798070567525844996598917476803"
			"157260780028538760589558632766878171540458953514382464234321326889"
			"464182768467546703537516986049910576551282076245490090389328944075"
			"868508455133942304583236903222948165808559332123348274797826204144"
			"723168738177180919299881250404026184124858368.0";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 18:\n";
		literal =
			"0."
			"000000000000000000000000000000000000000000000000000000000000000000"
			"000000000000000000000000000000000000000000000000000000000000000000"
			"000000000000000000000000000000000000000000000000000000000000000000"
			"000000000000000000000000000000000000000000000000000000000000000000"
			"0000000000000000000000000000000000000000002225";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 19:\n";
		literal =
			"-17976931348623157081452742373170435679807056752584499659891747680"
			"315726078002853876058955863276687817154045895351438246423432132688"
			"946418281290461012658166227876592237526246144346324838481774044009"
			"484224352822791349060359920537138012257204926350470337838327169061"
			"3285176307260982953545164784849303840192292864.0";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 20:\n";
		literal = "340282346638528859811704183484516925440.0";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 21:\n";
		literal =
			"0."
			"000000000000000000000000000000000000000000001401298464324817070923"
			"729583289916131280";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
	{
		std::cout << "TEST 22:\n";
		literal = "-340282346638528859811704183484516925440.0";
		std::cout << "input: " << literal << "\n\n";
		ScalarConverter::convert(literal);
		std::cout << "____________________\n\n";
	}
}

int main(int ac, char **av) {
	if (ac == 1) {
		runTests();
		exit(1);
	}
	for (int i = 1; i < ac; ++i) {
		std::string value = av[i];
		std::cout << "TEST : " << i << "\n";
		std::cout << "input: " << av[i] << "\n\n";
		ScalarConverter::convert(value);
		std::cout << "____________________\n";
		if (i + 1 != ac)
			std::cout << "\n";
	}
}

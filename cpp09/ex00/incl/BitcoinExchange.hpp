#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <stdexcept>
#include <string>

class BitcoinExchange {
	private:
		static std::map<std::string, double> _data;
		static constexpr float				 _minValue = 0;
		static constexpr float				 _maxValue = 1000;
		static std::regex					 _validInput;
		static std::regex					 _dateRegex;

		static void loadDataFromCSVLine(const std::string &line);
		static void processInputLine(const std::string &line);
		static void printError(const std::string &msg,
							   const std::string *line = nullptr);
		static bool getDateFromInputFile(const std::string &line,
										 std::string	   &date);
		static bool getAmountFromInputFile(const std::string &line,
										   double			 &amount);
		static void getPriceFromDatabase(const std::string &date,
										 double			   &price);

	public:
		BitcoinExchange(void) = delete;
		BitcoinExchange(const BitcoinExchange &other) = delete;
		BitcoinExchange &operator=(const BitcoinExchange &other) = delete;
		~BitcoinExchange(void) = delete;

		static void loadDataBase(void);
		static void parseInputFile(const std::string &input);
};

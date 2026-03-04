#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange {
	private:
		static std::map<std::string, float> _data;
		static constexpr float				_minValue = 0;
		static constexpr float				_maxValue = 1000;

	public:
		BitcoinExchange(void) = delete;
		BitcoinExchange(const BitcoinExchange &other) = delete;
		BitcoinExchange &operator=(const BitcoinExchange &other) = delete;
		~BitcoinExchange(void) = delete;

		static void loadDataBase(void);
		static void openInputFile(const std::string &input);
		static void parseDatabaseFile(const std::string);
		static void parseInputFile(const std::string);
};

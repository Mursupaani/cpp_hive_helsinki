#include "BitcoinExchange.hpp"

#include <fstream>
#include <string>

void BitcoinExchange::loadDataBase(void) {
	std::ifstream dataCSV("./data.csv");

	if (dataCSV.is_open() == false)
		throw(std::runtime_error("Couldn't open 'data.csv'"));
	std::string line;
	while (std::getline(dataCSV, line)) {}
}

void BitcoinExchange::openInputFile(const std::string &inputFile) {
	std::ifstream input(inputFile);
	if (input.is_open() == false)
		throw(std::runtime_error("Couldn't open '" + inputFile + "'"));
}

void BitcoinExchange::parseDatabaseFile(const std::string) {}

void BitcoinExchange::parseInputFile(const std::string) {}

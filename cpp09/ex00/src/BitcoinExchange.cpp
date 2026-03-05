#include "BitcoinExchange.hpp"

#include <fstream>
#include <iterator>
#include <string>

std::map<std::string, double> BitcoinExchange::_data;
std::regex					  BitcoinExchange::_dateRegex(
	   "^20\\d{2}-(0\\d{1}|1[0-2])-[0-3]{1}\\d{1}");

void BitcoinExchange::getDateAndValueFromDatabase(const std::string &line) {
	std::string date = line.substr(0, 10);
	std::string value = line.substr(11);

	try {
		_data[date] = std::stod(value);
	} catch (std::exception &e) {
		std::cerr << "Couldn't add '" << line << "' from database" << std::endl;
	}
}

void BitcoinExchange::loadDataBase(void) {
	std::ifstream dataCSV("./data.csv");

	if (!dataCSV)
		throw(std::runtime_error("Couldn't open 'data.csv'"));
	std::string line;
	std::getline(dataCSV, line);
	while (std::getline(dataCSV, line)) {
		getDateAndValueFromDatabase(line);
	}
}

void BitcoinExchange::openInputFile(const std::string &inputFile) {
	std::ifstream input(inputFile);
	if (!input)
		throw(std::runtime_error("Couldn't open '" + inputFile + "'"));
}

void BitcoinExchange::parseDatabaseFile(const std::string) {}

void BitcoinExchange::parseInputFile(const std::string) {}

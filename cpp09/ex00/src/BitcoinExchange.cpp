#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::_data;
std::regex					  BitcoinExchange::_dateRegex(
	   "[2-9]\\d{3}-(0\\d{1}|1[0-2])-([0-2]\\d|3[0-1])");
std::regex BitcoinExchange::_validInput(
	"^[2-9]\\d{3}-(0\\d|1[0-2])-[0-3]\\d\\s\\|\\s\\d+(\\.\\d+)?$");

void BitcoinExchange::loadDataFromCSVLine(const std::string &line) {
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
		loadDataFromCSVLine(line);
	}
	if (_data.size() == 0)
		throw(std::runtime_error("'data.csv' doesn't contain data"));
}

bool BitcoinExchange::getDateFromInputFile(const std::string &line,
										   std::string		 &date) {
	std::smatch dateMatch;

	if (std::regex_search(line, dateMatch, _dateRegex)) {
		date = *dateMatch.begin();
		if (date < _data.begin()->first) {
			printError("too early date", &date);
			return (false);
		}
	} else {
		printError("invalid date", &line);
		return (false);
	}
	return (true);
}

void BitcoinExchange::printError(const std::string &msg,
								 const std::string *line) {
	if (line)
		std::cout << "Error: " << msg << " => " << *line << "\n";
	else
		std::cout << "Error: " << msg << "\n";
}

bool BitcoinExchange::getAmountFromInputFile(const std::string &line,
											 double			   &amount) {
	size_t pos = line.find('|');
	if (pos++ != std::string::npos) {
		try {
			amount = std::stof(&line[pos]);
		} catch (std::exception &e) {
			printError(e.what());
			return (false);
		}
		if (amount < 0) {
			printError("number is negative");
			return (false);
		} else if (amount > 1000) {
			printError("number is too large");
			return (false);
		}
	} else
		return (false);
	return (true);
}

void BitcoinExchange::getPriceFromDatabase(const std::string &date,
										   double			 &price) {
	auto it = _data.begin();
	for (; it != _data.end(); ++it) {
		if (it->first == date) {
			{
				price = it->second;
				break;
			}
		} else if (it->first > date && it != _data.begin()) {
			{
				--it;
				price = it->second;
				break;
			}
		}
	}
	if (it == _data.end() && it != _data.begin()) {
		--it;
		price = it->second;
	}
}

void BitcoinExchange::processInputLine(const std::string &line) {
	std::smatch validMatch;
	std::string date;
	double		amount;
	double		price;

	if (!getAmountFromInputFile(line, amount))
		return;
	if (!getDateFromInputFile(line, date))
		return;
	if (!std::regex_search(line, validMatch, _validInput)) {
		printError("invalid line format", &line);
		return;
	}
	getPriceFromDatabase(date, price);
	std::cout << date << " => " << amount << " = " << (amount * price)
			  << std::endl;
}

void BitcoinExchange::parseInputFile(const std::string &inputFile) {
	std::ifstream input(inputFile);
	if (!input)
		throw(std::runtime_error("Couldn't open '" + inputFile + "'"));
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)) {
		processInputLine(line);
	}
}

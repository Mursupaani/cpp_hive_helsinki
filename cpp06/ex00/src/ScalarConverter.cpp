#include "ScalarConverter.hpp"

static void printChar(const double value) {
	if (value >= 32 && value <= 126)
		std::cout << "char: " << static_cast<char>(value) << "\n";
	else if (value >= 0 && value <= 255)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: Impossible\n";
}

static void printInt(const double value) {
	if (value <= INT_MAX && value >= INT_MIN)
		std::cout << "int: " << static_cast<int>(value) << "\n";
	else
		std::cout << "int: Impossible\n";
}

static void printFloat(const double value) {
	float f = static_cast<float>(value);
	if (std::floor(f) == f && f != std::numeric_limits<float>::infinity() &&
		f != -std::numeric_limits<float>::infinity())
		std::cout << "float: " << f << ".0f\n";
	else
		std::cout << "float: " << f << "f\n";
}

static void printDouble(const double value) {
	if (std::floor(value) == value &&
		value != std::numeric_limits<double>::infinity() &&
		value != -std::numeric_limits<double>::infinity())
		std::cout << "double: " << value << ".0\n";
	else
		std::cout << "double: " << value << "\n";
}

void ScalarConverter::convertAndPrintValue(const double value, valueType type,
										   bool exceptionHappened) {
	if (!exceptionHappened && type != NONE) {
		printChar(value);
		printInt(value);
		printFloat(value);
		printDouble(value);
	} else {
		std::cout << "char: impossible \n";
		std::cout << "int: impossible \n";
		std::cout << "float: impossible \n";
		std::cout << "double: impossible \n";
	}
}

ScalarConverter::valueType ScalarConverter::deduceType(
	const std::string &literal) {
	std::regex	reChar("^.$");
	std::regex	reInt("^-?\\d+$");
	std::regex	reFloat("^-?\\d+\\.\\d+f$");
	std::regex	reDouble("^-?\\d+\\.\\d+$");
	std::regex	reNanF("^nanf$");
	std::regex	reNegInfF("^\\-inff$");
	std::regex	rePosInfF("^\\+inff$");
	std::regex	reNan("^nan$");
	std::regex	reNegInf("^\\-inf$");
	std::regex	rePosInf("^\\+inf$");
	std::smatch match;

	if (std::regex_search(literal, match, reInt))
		return (INT);
	else if (std::regex_search(literal, match, reFloat))
		return (FLOAT);
	else if (std::regex_search(literal, match, reDouble))
		return (DOUBLE);
	else if (std::regex_search(literal, match, reChar))
		return (CHAR);
	else if (std::regex_search(literal, match, reNanF))
		return (NANF);
	else if (std::regex_search(literal, match, reNegInfF))
		return (NEGINFF);
	else if (std::regex_search(literal, match, rePosInfF))
		return (POSINFF);
	else if (std::regex_search(literal, match, reNan))
		return (NANF);
	else if (std::regex_search(literal, match, reNegInf))
		return (NEGINF);
	else if (std::regex_search(literal, match, rePosInf))
		return (POSINF);
	else
		return (NONE);
}

void ScalarConverter::convert(const std::string &literal) {
	double value;
	bool   exceptionHappened = false;

	valueType type = deduceType(literal);
	switch (type) {
		case CHAR:
			value = literal[0];
			break;
		case INT:
			try {
				value = std::stoi(literal);
			} catch (std::out_of_range &e) {
				exceptionHappened = true;
			} catch (std::invalid_argument &e) {
				exceptionHappened = true;
			}
			break;
		case FLOAT:
			try {
				value = std::stof(literal);
			} catch (std::out_of_range &e) {
				exceptionHappened = true;
			} catch (std::invalid_argument &e) {
				exceptionHappened = true;
			}
			break;
		case DOUBLE:
			try {
				value = std::stod(literal);
			} catch (std::out_of_range &e) {
				exceptionHappened = true;
			} catch (std::invalid_argument &e) {
				exceptionHappened = true;
			}
			break;
		case NANF:
			value = std::numeric_limits<float>::quiet_NaN();
			break;
		case NEGINFF:
			value = -std::numeric_limits<float>::infinity();
			break;
		case POSINFF:
			value = std::numeric_limits<float>::infinity();
			break;
		case NAND:
			value = std::numeric_limits<double>::quiet_NaN();
			break;
		case NEGINF:
			value = -std::numeric_limits<double>::infinity();
			break;
		case POSINF:
			value = std::numeric_limits<double>::infinity();
			break;
		case NONE:
			value = 0;
			break;
	}
	convertAndPrintValue(value, type, exceptionHappened);
}

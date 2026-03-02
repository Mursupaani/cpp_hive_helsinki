#include "Phonebook.hpp"

Phonebook::Phonebook() : _pos(-1), _size(0), _status(0)
{
}

Phonebook::~Phonebook()
{
}

int	Phonebook::getNextPos()
{
	_pos++;
	_pos %= 8;
	return (_pos);
}

void	Phonebook::addContact()
{
	std::string	input;
	int			pos;
	bool		valid = true;

	std::cout << _size << std::endl;
	pos = getNextPos();
	while (input.length() == 0)
	{
		clearScreen();
		std::cout << "Please input first name: " << std::endl;
		if (!std::getline(std::cin, input))
			exit(EXIT_SUCCESS);
	}
	_contacts[pos].setFirstName(input);
	input.clear();
	while (input.length() == 0)
	{
		clearScreen();
		std::cout << "Please input last name: " << std::endl;
		if (!std::getline(std::cin, input))
			exit(EXIT_SUCCESS);
	}
	_contacts[pos].setLastName(input);
	input.clear();
	while (input.length() == 0)
	{
		clearScreen();
		std::cout << "Please input nick name: " << std::endl;
		if (!std::getline(std::cin, input))
			exit(EXIT_SUCCESS);
	}
	_contacts[pos].setNickName(input);
	input.clear();
	while (input.length() == 0 || phonenumberIsValid(input, valid) == false)
	{
		clearScreen();
		std::cout << "Please input phone number: " << std::endl;
		if (valid == false)
			std::cout << "(Please use only valid characters +-() 0123456789)" << std::endl;
		if (!std::getline(std::cin, input))
			exit(EXIT_SUCCESS);
	}
	_contacts[pos].setPhoneNumber(input);
	input.clear();
	while (input.length() == 0)
	{
		clearScreen();
		std::cout << "Please input darkest secret: " << std::endl;
		if (!std::getline(std::cin, input))
			exit(EXIT_SUCCESS);
	}
	_contacts[pos].setDarkestSecret(input);
	_size++;
	if (_size > _max)
		_size = _max;
}

void	Phonebook::searchWindow()
{
	if (_size == 0)
	{
		std::cout << "No saved contacts" << std::endl;
		setStatus(2);
		return ;
	}
	printSearchHeader();
	chooseContact();
}

void	Phonebook::chooseContact()
{
	std::string	input;
	int			index;

	while (true)
	{
		printContactsForSearch();
		std::cout << "\nChoose index to get details (or [B]ACK to go back): " << std::endl;
		if (!std::getline(std::cin, input))
			exit(EXIT_SUCCESS);
		for (unsigned long i = 0; i < input.length(); ++i)
			input[i] = std::tolower(input[i]);
		clearScreen();
		if (input == "back" || input == "b")
			return ;
		try
		{
			index = std::stoi(input);
		}
		catch (...)
		{
			std::cout << "Please input a valid number between 0 and " + std::to_string(_size - 1) << std::endl;
			continue ;
		}
		if (index >= _size || index < 0)
		{
			std::cout << "Please choose an index between 0 and " + std::to_string(_size - 1) << std::endl;
			continue ;
		}
		printContact(index);
		break ;
	}
	std::cout << "\nPress ENTER to continue..." << std::endl;
	if (!std::getline(std::cin, input))
		exit(EXIT_SUCCESS);
}

void	Phonebook::printContact(int index)
{
	clearScreen();
	std::cout << _contacts[index].getFirstName() << std::endl;
	std::cout << _contacts[index].getLastName() << std::endl;
	std::cout << _contacts[index].getNickName() << std::endl;
	std::cout << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << _contacts[index].getDarkestSecret() << std::endl;
}


void	Phonebook::printSearchHeader()
{
	std::cout << "|";
	std::cout << std::setw (10) << std::right;
	std::cout << "INDEX";
	std::cout << "|";
	std::cout << std::setw (10) << std::right;
	std::cout << "FIRST NAME";
	std::cout << "|";
	std::cout << std::setw (10) << std::right;
	std::cout << "LAST NAME";
	std::cout << "|";
	std::cout << std::setw (10) << std::right;
	std::cout << "NICK NAME";
	std::cout << "|" << std::endl;
}

void	Phonebook::printContactsForSearch()
{
	for (int i = 0; i < _size; ++i)
	{
		std::cout << "|";
		std::cout << std::setw (10) << std::right;
		std::cout << i;
		std::cout << "|";
		std::cout << std::setw (10) << std::right;
		std::cout << truncateStr(_contacts[i].getFirstName(), 10);
		std::cout << "|";
		std::cout << std::setw (10) << std::right;
		std::cout << truncateStr(_contacts[i].getLastName(), 10);
		std::cout << "|";
		std::cout << std::setw (10) << std::right;
		std::cout <<truncateStr(_contacts[i].getNickName(), 10);
		std::cout << "|" << std::endl;
	}
}

void	Phonebook::setStatus(int status)
{
	_status = status;
}

int	Phonebook::getStatus()
{
	return (_status);
}

std::string	Phonebook::truncateStr(const std::string str, const size_t maxLen)
{
	if (str.length() <= maxLen)
		return (str);
	return (str.substr(0, maxLen - 1)) + ".";
}

void Phonebook::clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

bool	Phonebook::phonenumberIsValid(std::string number, bool &valid)
{
	std::string	validCharacters = "+-() 0123456789";

	for (unsigned long i = 0; i < number.length(); ++i)
	{
		valid = false;
		for (unsigned long j = 0; j < validCharacters.length(); ++j)
		{
			if (number[i] == validCharacters[j])
			{
				valid = true;
				break ;
			}
		}
		if (valid == false)
			return (false);
	}
	return (true);
}

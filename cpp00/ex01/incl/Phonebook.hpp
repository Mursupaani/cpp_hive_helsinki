#pragma once
# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();

		void	addContact();
		int		getNextPos();
		void	searchWindow();
		int		getStatus();
		void	setStatus(int status);
		void	clearScreen();
	private:
		static const int	_max = 8;
		int					_pos;
		int					_size;
		Contact				_contacts[_max];
		int					_status;

		void		printContactsForSearch();
		void		printSearchHeader();
		void		chooseContact();
		void		printContact(int index);
		// bool		phonenumberIsValid(std::string number);
		bool		phonenumberIsValid(std::string number, bool &valid);
		std::string	truncateStr(std::string str, size_t maxLen);
};

#pragma once
# include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		// Getters:
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

		// Setters:
		void	setFirstName(const std::string firstName);
		void	setLastName(const std::string lastName);
		void	setNickName(const std::string nickName);
		void	setPhoneNumber(const std::string phoneNumber);
		void	setDarkestSecret(const std::string darkestSecret);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

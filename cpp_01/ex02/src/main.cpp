#include <string>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of string :\t" << &string << std::endl;
	std::cout << "Address in stringPTR :\t" << stringPTR << std::endl;
	std::cout << "Address in stringRSF :\t" << &stringREF << std::endl;
	std::cout << "Value of string :\t" <<string << std::endl;
	std::cout << "Value in stringPTR :\t" << *stringPTR << std::endl;
	std::cout << "Value in stringRSF :\t" << stringREF << std::endl;
	return (EXIT_SUCCESS);
}

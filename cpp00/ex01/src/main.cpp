#include "Phonebook.hpp"

void	handleUserInput(std::string input, Phonebook &pb)
{
	pb.clearScreen();
	pb.setStatus(0);
	if (input == "a" || input == "add")
		pb.addContact();
	else if (input == "s" || input == "search")
		pb.searchWindow();
	else if (input == "e" || input == "exit")
		std::exit(EXIT_SUCCESS);
	else
		pb.setStatus(1);
}

std::string getUserInput()
{
	std::string	input;
	std::cout << "Please input what you wish to do:" << std::endl;
	std::cout << "[A]DD\t\t- Add a new contact to phonebook" << std::endl;
	std::cout << "[S]EARCH\t- Display contact" << std::endl;
	std::cout << "[E]XIT\t\t- Add a new contact to phonebook" << std::endl;
	if (!std::getline(std::cin, input))
		exit(EXIT_SUCCESS);
	for (unsigned long i = 0; i < input.length(); ++i)
		input[i] = std::tolower(input[i]);
	return (input);
}

int	main(void)
{
	Phonebook	pb;
	std::string	input;

	while (true)
	{
		pb.clearScreen();
		if (pb.getStatus() == 1)
			std::cout << "Invalid input \"" << input
				<< "\". Please try again\n" << std::endl;
		if (pb.getStatus() == 2)
			std::cout << "No saved contacts\n" << std::endl;
		input = getUserInput();
		handleUserInput(input, pb);
	}
	return (EXIT_SUCCESS);
}

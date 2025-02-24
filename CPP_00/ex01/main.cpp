#include "PhoneBook.hpp"
#include <cstdlib>

int	main(void)
{
    PhoneBook PhoneBook;
    std::string input;

    while (1)
    {
        std::cout << "Imput Command(ADD, SEARCH, EXIT)" << std::endl;
        std::getline(std::cin, input);
        PhoneBook.checkCinInput();
        PhoneBook.handleInput(input);
        input.clear();
    }
    return (EXIT_FAILURE);
}
#include "Harl.hpp"

int main (int argc, char *argv[]) {

    // argcのチェック
    if (argc != 2){
        std::cout << "You must input one of the 'level' argument" << std::endl;
        std::cout << "'DEBUG', 'INFO', 'WARNING', 'ERROR'" << std::endl;
        std::cout << "Input Ex: ./Harl DEBUG" << std::endl;
        return (1);
    }
    
    Harl Harl;

    Harl.complain(std::string(argv[1]));

    return (0);
}
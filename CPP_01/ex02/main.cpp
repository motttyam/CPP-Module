#include <iostream>
#include <string>

int main () {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Address of string:    " << &string << std::endl;
    std::cout << "Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;

    std::cout << "Content of string:    " << string << std::endl;
    std::cout << "Content of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Content of stringREF: " << stringREF << std::endl;
}
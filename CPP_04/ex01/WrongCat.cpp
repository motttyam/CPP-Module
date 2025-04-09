#include "WrongCat.hpp"

WrongCat::WrongCat() {
    WrongCat::type = "WrongCat";
    std::cout << "[WrongCat]Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat]Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
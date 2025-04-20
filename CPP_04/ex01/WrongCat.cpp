#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "[WrongCat]Constructor called" << std::endl;
}


WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.getType()) {
    std::cout << "[WrongCat]Copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat]Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "[WrongCat]Copy assignmet operator called" << std::endl;
    if (this != &other) {
        this->setType(other.getType());
    }
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
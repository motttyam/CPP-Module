#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    WrongAnimal::type = "";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some WrongAnimals can bark, other WrongAnimals can't bark" << std::endl;
}

// getter func
std::string WrongAnimal::getType() const {
    return (type);
}

// setter func
void WrongAnimal::setType(const std::string& type) {
    WrongAnimal::type = type;
}


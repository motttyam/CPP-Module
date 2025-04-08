#include "Animal.hpp"

Animal::Animal() {
    Animal::type = "";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Some animals can bark, other animals can't bark" << std::endl;
}

// getter func
std::string Animal::getType() const {
    return (type);
}

// setter func
void Animal::setType(const std::string& type) {
    Animal::type = type;
}


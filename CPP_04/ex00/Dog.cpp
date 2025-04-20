#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "[Dog]Constructor called" << std::endl;
}


Dog::Dog(const Dog& other) : Animal(other.getType()) {
    std::cout << "[Dog]Copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "[Dog]Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog]Copy assignmet operator called" << std::endl;
    if (this != &other) {
        this->setType(other.getType());
    }
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "bowwow!" << std::endl;
}
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "[Cat]Constructor called" << std::endl;
}


Cat::Cat(const Cat& other) : Animal(other.getType()) {
    std::cout << "[Cat]Copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "[Cat]Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat]Copy assignmet operator called" << std::endl;
    if (this != &other) {
        this->setType(other.getType());
    }
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
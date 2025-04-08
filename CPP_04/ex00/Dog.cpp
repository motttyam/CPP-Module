#include "Dog.hpp"

Dog::Dog() {
    Dog::type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "bowwow!" << std::endl;
}
#include "Cat.hpp"

Cat::Cat() {
    Cat::type = "Cat";
    this->brain = new Brain();
    std::cout << "[Cat]Constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "[Cat]Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

// getter func
std::string Cat::getIdea(int index) const {
    return (this->brain->getIdea(index));
}

// setter func
void Cat::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}
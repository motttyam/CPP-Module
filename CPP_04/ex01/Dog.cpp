#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
    Dog::type = "Dog";
    this->brain = new Brain();
    std::cout << "[Dog]Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->brain = new Brain(*other.brain);
    std::cout << "[Dog]Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->setType(other.getType());
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "[Dog]Copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "[Dog]Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "bowwow!" << std::endl;
}

// getter func
std::string Dog::getIdea(int index) const {
    return (this->brain->getIdea(index));
}

// setter func
void Dog::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}
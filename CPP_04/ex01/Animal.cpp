#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "[Animal]Default Constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
    std::cout << "[Animal]Constructor called for " << this->getType() << std::endl;
}

Animal::Animal(const Animal& other) : type(other.getType()) {
    std::cout << "[Animal]Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal]Copy assignmet operator called" << std::endl;
    if (this != &other) {
        this->setType(other.getType());
    }
    return (*this);
}

Animal::~Animal() {
    std::cout << "[Animal]Destructor called" << std::endl;
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


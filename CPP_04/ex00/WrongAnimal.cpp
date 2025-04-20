#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    WrongAnimal::type = "";
    std::cout << "[WrongAnimal]Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
    std::cout << "[WrongAnimal]Constructor called for " << this->getType() << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.getType()) {
    std::cout << "[WrongAnimal]Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "[WrongAnimal]Copy assignmet operator called" << std::endl;
    if (this != &other) {
        this->setType(other.getType());
    }
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal]Destructor called" << std::endl;
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


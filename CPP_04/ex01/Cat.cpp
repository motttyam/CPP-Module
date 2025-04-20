#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
    Cat::type = "Cat";
    this->brain = new Brain();
    std::cout << "[Cat]Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->brain = new Brain(*other.brain);
    std::cout << "[Cat]Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->setType(other.getType());
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "[Cat]Copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "[Cat]Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

// getter func
std::string Cat::getIdea(int index) const {
    return (this->brain->getIdea(index));
}

// setter func
void Cat::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}
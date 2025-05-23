#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(const Ice& other) : AMateria(other.getType()) {}

Ice& Ice::operator=(const Ice& other){
    if (this != &other) 
        AMateria::operator=(other);
    return (*this);
} 

Ice::~Ice(){};

Ice * Ice::clone() const {
    return (new Ice());
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}

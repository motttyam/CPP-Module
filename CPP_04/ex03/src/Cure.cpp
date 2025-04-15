#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){};

Cure::Cure(const Cure& other) : AMateria(other.getType()) {}

Cure& Cure::operator=(const Cure& other){
    if (this != &other) 
        AMateria::operator=(other);
    return (*this);
} 

Cure::~Cure(){};

Cure * Cure::clone() const {
    return (new Cure());
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals '" << target.getName() << "'s wounds *" <<std::endl;
}
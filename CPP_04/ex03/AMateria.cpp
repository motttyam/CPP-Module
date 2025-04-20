#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(){}

AMateria::AMateria(const std::string& type) : _type(type) {};

AMateria::AMateria(const AMateria& other) : _type(other.getType()) {}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        this->_type = other.getType();
    }
    return (*this);
}

AMateria::~AMateria(){};

const std::string& AMateria::getType() const {
    return (_type);
}

void AMateria::use(ICharacter& target) {
    (void)target;
}

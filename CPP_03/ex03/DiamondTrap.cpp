#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), _name("") {
    ClapTrap::_name = "_clap_name";
    std::cout << "[DiamondTrap]Default constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const std::string& name)
:   ScavTrap(name),
    FragTrap(name),
    _name(name)
{
    ClapTrap::_name = name + "_clap_name";
    std::cout << "[DiamondTrap]Constructor called for " << this->_name << std::endl;
    this->setHP(FragTrap::getHP()); 
    this->setEP(ScavTrap::getEP());
    this->setATK(FragTrap::getATK());
}
DiamondTrap::DiamondTrap(const DiamondTrap& other)
:   ScavTrap(other),
    FragTrap(other),
    _name(other.getName())
{
    std::cout << "[DiamondTrap]Copy constructor called for " << this->_name << std::endl;
    ClapTrap::_name = other.getName() + "_clap_name";
    this->setHP(other.getHP()); 
    this->setEP(other.getEP());
    this->setATK(other.getATK());
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "[DiamondTrap]Copy assignment operator called for " << this->_name << std::endl;
    if (this != &other) {
        ClapTrap::_name = other.getName() + "_clap_name";
        this->setHP(other.getHP()); 
        this->setEP(other.getEP());
        this->setATK(other.getATK());
        this->_name = other.getName();
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "[DiamondTrap]Destructor called for " << this->_name << std::endl;
    std::cout << "Destroying DiamondTrap with " 
        << this->getHP() << " hit points, " 
        << this->getEP() << " energy points, and " 
        << this->getATK() << " attack damage." << std::endl;
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap Name is " << this->_name << std::endl;
    std::cout << "ClapTrap Name is " << ClapTrap::_name << std::endl;
}


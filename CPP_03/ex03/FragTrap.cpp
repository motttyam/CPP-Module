#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "[FragTrap]Default constructor called" << std::endl;
    _HP = 100;
    _EP = 100;
    _ATK = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "[FragTrap]Constructor called for " << this->getName() << std::endl;
    _HP = 100;
    _EP = 100;
    _ATK = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "[FragTrap]Copy constructor called for " << other.getName() << std::endl;
    this->setName(other.getName());
    this->setHP(other.getHP());
    this->setEP(other.getEP());
    this->setATK(other.getATK());
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "[FragTrap]Copy Assignment operator called for " << other.getName() << std::endl;
    if (this != &other) {
        this->setName(other.getName());
        this->setHP(other.getHP());
        this->setEP(other.getEP());
        this->setATK(other.getATK());
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "[FragTrap]Destructor call for " << this->getName() << std::endl;
    // std::cout << "Destroying FragTrap with " 
    //     << this->_HP << " hit points, " 
    //     << this->_EP << " energy points, and " 
    //     << this->_ATK << " attack damage." << std::endl;
}

void FragTrap::highFiveGuys() {
    std::cout << this->getName() << " 'Let's have a high five!'" << std::endl;
}

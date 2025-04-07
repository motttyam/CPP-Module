#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _HP = 100;
    _EP = 100;
    _ATK = 30;
    std::cout << "FragTrap constructor called for " << this->getName() << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor call for " << this->getName() << std::endl;
    // std::cout << "Destroying FragTrap with " 
    //     << this->_HP << " hit points, " 
    //     << this->_EP << " energy points, and " 
    //     << this->_ATK << " attack damage." << std::endl;
}

void FragTrap::highFiveGuys() {
    std::cout << this->getName() << " 'Let's have a high five!'" << std::endl;
}

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _HP = 100;
    _EP = 50;
    _ATK = 20;
    std::cout << "ScavTrap constructor called for " << this->getName() << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor call for " << this->getName() << std::endl;
    // std::cout << "Destroying ScavTrap with " 
    //     << this->_HP << " hit points, " 
    //     << this->_EP << " energy points, and " 
    //     << this->_ATK << " attack damage." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << this->getName() << " has entered Gate keeper mode." << std::endl;
}


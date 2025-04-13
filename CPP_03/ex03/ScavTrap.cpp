#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "[ScavTrap]Constructor called for " << this->getName() << std::endl;
    _HP = 100;
    _EP = 50;
    _ATK = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "[ScavTrap]Copy constructor called for " << other.getName() << std::endl;
    this->setName(other.getName());
    this->setHP(other.getHP());
    this->setEP(other.getEP());
    this->setATK(other.getATK());
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "[ScavTrap]Copy Assignment opereator called for " << other.getName() << std::endl;
    if (this != &other) {
        this->setName(other.getName());
        this->setHP(other.getHP());
        this->setEP(other.getEP());
        this->setATK(other.getATK());
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "[ScavTrap]Destructor called for " << this->getName() << std::endl;
    // std::cout << "Destroying ScavTrap with " 
    //     << this->_HP << " hit points, " 
    //     << this->_EP << " energy points, and " 
    //     << this->_ATK << " attack damage." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << this->getName() << " has entered Gate keeper mode." << std::endl;
}


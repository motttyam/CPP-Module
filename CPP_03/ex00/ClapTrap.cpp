#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _HP(10), _EP(10), _ATK(0) {
    std::cout << "Constructor Called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called for " << this->_name << std::endl;
    std::cout << "Destroying ClapTrap with " 
              << this->_HP << " hit points, " 
              << this->_EP << " energy points, and " 
              << this->_ATK << " attack damage." << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    if (this->_HP == 0 || this->_EP == 0) {
        std::cout << _name << " is unable to attack!" << std::endl;
        return;
    }
    std::cout << _name << " attacks " << target 
              << ", causing " << _ATK 
              << " points of damage!" << std::endl;
    _EP--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_HP == 0) {
        std::cout << _name << " is already destroyed!" << std::endl;
        return;
    }
    this->_HP -= amount;
    if (this->_HP <= 0) {
        this->_HP = 0;
        std::cout << this->_name << " has been destroyed!" << std::endl;
    } else {
        std::cout << this->_name << " takes " << amount 
                  << " points of damage! Remaining HP: " 
                  << this->_HP << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_HP == 0 || this->_EP == 0) {
        std::cout << this->_name << " is unable to be repaired!" << std::endl;
        return;
    }
    _HP += amount;
    _EP--;
    std::cout << this->_name << " Repairs itself for " 
              << amount << " hit points! Current HP: " 
              << this->_HP << std::endl;
}

// getter func
const std::string& ClapTrap::getName() const {
    return (this->_name);
}
unsigned int ClapTrap::getHP() const {
    return (this->_HP);
}
unsigned int ClapTrap::getEP() const {
    return (this->_EP);
}
unsigned int ClapTrap::getATK() const {
    return (this->_ATK);
}

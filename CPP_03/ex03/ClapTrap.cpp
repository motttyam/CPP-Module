#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _HP(10), _EP(10), _ATK(5) {
    std::cout << "ClapTrap constructor Called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
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

// setter func
void ClapTrap::setName(const std::string& name) {
    this->_name = name;
}

void ClapTrap::setHP(unsigned int HP) {
    this->_HP = HP;
}

void ClapTrap::setEP(unsigned int EP) {
    this->_EP = EP;
}

void ClapTrap::setATK(unsigned int ATK) {
    this->_ATK = ATK;
}

void ClapTrap::setAll(unsigned int HP, unsigned int EP, unsigned int ATK) {
    this->_HP = HP;
    this->_EP = EP;
    this->_ATK = ATK;
}
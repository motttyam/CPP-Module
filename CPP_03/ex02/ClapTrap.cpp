#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("") {
    std::cout << "[ClapTrap]Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _HP(10), _EP(10), _ATK(0) {
    std::cout << "[ClapTrap]Constructor called for " << this->getName() << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other.getName()), _HP(other.getHP()), _EP(other.getEP()), _ATK(other.getATK()) {
    std::cout << "[ClapTrap]Copy constructor called for " << other.getName() << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << "[ClapTrap]Copy assignment operator called for " << other.getName() << std::endl;
    if (this != &other) {
        _name = other.getName();
        _HP = other.getHP();
        _EP = other.getEP();
        _ATK = other.getATK();
    }
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "[ClapTrap]Destructor called for " << this->getName() << std::endl;
    // std::cout << "Destroying ClapTrap with " 
    //           << this->getHP() << " hit points, " 
    //           << this->getEP() << " energy points, and " 
    //           << this->getATK() << " attack damage." << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    if (this->getHP() == 0 || this->getEP() == 0) {
        std::cout << this->getName() << " is unable to attack!" << std::endl;
        return;
    }
    std::cout << getName() << " attacks " << target 
              << ", causing " << getATK()
              << " points of damage!" << std::endl;
    setEP(this->getEP() - 1);
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->getHP() == 0) {
        std::cout << this->getName() << " is already destroyed!" << std::endl;
        return;
    }
    if (this->getHP() <= amount) {
        this->setHP(0);
        std::cout << this->getName() << " has been destroyed!" << std::endl;
    } else {
        setHP(getHP() - amount);
        std::cout << this->getName() << " takes " << amount 
                  << " points of damage! Remaining HP: " 
                  << this->getHP() << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->getHP() == 0 || this->getEP() == 0) {
        std::cout << this->getName() << " is unable to be repaired!" << std::endl;
        return;
    }
    this->setHP(this->getHP() + amount);
    setEP(getEP() - 1);
    std::cout << this->getName() << " Repairs itself for " 
              << amount << " hit points! Current HP: " 
              << this->getHP() << std::endl;
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

void ClapTrap::setAll(const std::string& name, unsigned int HP, unsigned int EP, unsigned int ATK) {
    this->_name = name;
    this->_HP = HP;
    this->_EP = EP;
    this->_ATK = ATK;
}
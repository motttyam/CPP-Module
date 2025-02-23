#include "includes/Weapon.hpp"
#include "includes/HumanB.hpp"

HumanB::HumanB(const std::string &name, Weapon &weapon) : _name(name), _weapon(&weapon) {}

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack() const {
    if (_weapon){
        std::cout << _name << " attacks with their "
            << _weapon->getType() << std::endl;
    }
    else {
        std::cout << this->_name << " attacks with their "
            << "hands" << std::endl;
    }
}

void HumanB::setWeapon (Weapon &weapon){
    _weapon = &weapon;
}
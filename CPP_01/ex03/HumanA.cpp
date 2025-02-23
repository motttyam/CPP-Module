#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack(){
    std::cout << this->_name << " attacks with their "
        << this->_weapon.getType() << std::endl;
}

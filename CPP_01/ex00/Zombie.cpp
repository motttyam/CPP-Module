#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie (std::string name) : name(name) {}

Zombie::~Zombie() {
    std::cout << this->name << " has been purified. R.I.P." << std::endl;
}

void Zombie::announce (void) const {
    std::cout << this->name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}
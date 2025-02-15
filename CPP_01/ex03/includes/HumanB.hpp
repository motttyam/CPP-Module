#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
    public:
        HumanB(const std::string &name, Weapon Weapon);
        ~HumanB();

    private:
        std::string name;
};

#endif
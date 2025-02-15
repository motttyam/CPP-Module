#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA{
    public:
        HumanA(const std::string &name, Weapon Weapon);
        ~HumanA();

    private:
        std::string name;
};

#endif
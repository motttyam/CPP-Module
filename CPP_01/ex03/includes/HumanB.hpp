#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
    public:
        HumanB(const std::string &name, Weapon &weapon);
        HumanB(const std::string &name);
        ~HumanB();
        void attack() const ;
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon *_weapon;

};

#endif
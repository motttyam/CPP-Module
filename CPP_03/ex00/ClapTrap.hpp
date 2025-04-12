#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    private:
        std::string _name;
        unsigned int _HP;
        unsigned int _EP;
        unsigned int _ATK;

    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // getter func
        const std::string& getName() const;
        unsigned int getHP() const;
        unsigned int getEP() const;
        unsigned int getATK() const;

        // setter func
        void setName(const std::string& name);
        void setHP(unsigned int HP);
        void setEP(unsigned int EP);
        void setATK(unsigned int ATK);
        void setAll(const std::string& name, unsigned int HP, unsigned int EP, unsigned int ATK);

};

#endif
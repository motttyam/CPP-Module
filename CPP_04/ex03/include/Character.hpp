#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter {
    private:
        std::string _name;
        static const int slotSize = 4;
        static const int groundSize = 128;
        AMateria *_slots[slotSize];
        AMateria *_grounds[groundSize];
        int _ground_i;
    
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();
        const std::string& getName() const;
        const int& getGroundIndex() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
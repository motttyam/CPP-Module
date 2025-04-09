#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>

// 循環参照を防ぐためにクラスを宣言のみ行う
class AMateria;

class ICharacter{
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif
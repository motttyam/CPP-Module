#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

// 循環参照を防ぐためにクラスを宣言のみ行う
class ICharacter;

// Abstract Materia
class AMateria {
    protected:
        std::string _type;

    public:
        AMateria(const std::string& type);
        virtual ~AMateria();
        const std::string& getType() const ;
        virtual AMateria* clone () const = 0; // 純粋仮想関数
        virtual void use (ICharacter& target);
};

#endif
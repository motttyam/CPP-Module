#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        std::string getType() const;
        void setType(const std::string& type);
        virtual void makeSound() const;
};

#endif
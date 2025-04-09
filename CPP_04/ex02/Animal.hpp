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
        // Abstract Classとなるように pure virtual classとして設定
        virtual void makeSound() const = 0;
};

#endif
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    Animal *i = new Dog();
    Animal *j = new Cat();

    // Animalクラスはインスタンス化するとコンパイルエラーする
    // Animal a;

    delete i;
    delete j;
    return (0);
}

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(){
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();    // 猫の鳴き声
    j->makeSound();    // 犬の鳴き声
    meta->makeSound(); // Animalの鳴き声

    delete meta;
    delete j;
    delete i;

    // const WrongAnimal *wrong = new WrongAnimal();
    // const WrongAnimal *wrongCat = new WrongCat();
    // std::cout << wrongCat->getType() << std::endl;
    // wrongCat->makeSound(); // WrongCatの鳴き声
    // wrong->makeSound(); // WrongAnimalの鳴き声
    // delete wrong;
    // delete wrongCat;

    return (0);
}
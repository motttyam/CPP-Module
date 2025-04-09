#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "==== Basic Allocation Test ====" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n==== Array of Animals Test ====" << std::endl;
    const int N = 4;
    Animal* animals[N];
    for (int i = 0; i < N / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = N / 2; i < N; i++) {
        animals[i] = new Cat();
    }

    std::cout << "\n==== Deleting Array of Animals ====" << std::endl;
    for (int i = 0; i < N; i++) {
        delete animals[i]; // ← Animal* から delete（仮想デストラクタのチェック）
    }

    std::cout << "\n==== Deep Copy Test ====" << std::endl;
    Dog basicDog;
    basicDog.setIdea(0, "Chase the cat!");

    Dog copiedDog = basicDog; // コピーコンストラクタが呼ばれる
    copiedDog.setIdea(0, "Sleep on the sofa");

    std::cout << "basicDog idea[0]: " << basicDog.getIdea(0) << std::endl;
    std::cout << "copiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    return 0;
}

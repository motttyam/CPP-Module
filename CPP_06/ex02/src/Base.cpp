#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base(){}

Base * generate(void) {
    
    static bool seed_is_set = false;
    if (!seed_is_set) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seed_is_set = true;
    }

    int randValue = std::rand();
    switch (randValue % 3){
        case 0: return (new A());
        case 1: return (new B());
        case 2: return (new C());
        default: break;
    }
    return (NULL);
}

void identify(Base *p) {
    if (p == NULL)
        std::cout << "null" << std::endl;

    else if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;

    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;

    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A&>(p);
         std::cout << "A" << std::endl;
         return ;
    }
    catch (...){}

        try {
        (void)dynamic_cast<B&>(p);
         std::cout << "B" << std::endl;
         return ;
    }
    catch (...){}

        try {
        (void)dynamic_cast<C&>(p);
         std::cout << "C" << std::endl;
         return ;
    }
    catch (...){}

    std::cout << "Unknown" << std::endl;
}
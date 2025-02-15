#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
    Zombie *newZombie;

    newZombie = new Zombie(name);
    if (!newZombie)
        return (NULL);
    (*newZombie).announce();
    return (newZombie);
}
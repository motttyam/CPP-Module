#include "Zombie.hpp"

int main (){
    Zombie *Zombie;
    
    randomChump("pochi");
    Zombie = newZombie("tama");
    if (!Zombie)
        return (1);
    delete Zombie;
    return (0);
}
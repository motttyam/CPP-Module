#include "Zombie.hpp"

int main (){
    int N = 10;
    std::string name = "zombie";
    Zombie *Zombies;

    Zombies = zombieHorde(N, name);
    if (!Zombies){
        return (1);
    }

    for (int i = 0; i < N; i++)
        Zombies[i].announce();

    delete[] Zombies;


    return (0);
}
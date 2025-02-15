#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);

	Zombie *Zombies = new Zombie[N];
    if(!Zombies){
        return (NULL);
    }

	for (int i = 0; i < N; i++)
	{
		Zombies[i].setName(name);
	}
    return (Zombies);
}
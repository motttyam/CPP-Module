#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
  public:
	Zombie(std::string);
	Zombie();
	~Zombie();
	void announce(void) const;
    void setName(std::string name);

  private:
	std::string name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
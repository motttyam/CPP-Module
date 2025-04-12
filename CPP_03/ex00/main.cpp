#include <ClapTrap.hpp>

int main () {
    ClapTrap targetA("Alice");
    ClapTrap targetB("Bob");
    ClapTrap targetC("Charlie");

    std::cout << "------------------------" << std::endl;
    targetA.attack("Bob");
    targetB.takeDamage(targetA.getATK());
    std::cout << "------------------------" << std::endl;
    targetB.beRepaired(5);
    std::cout << "------------------------" << std::endl;
    targetB.attack("Alice");
    targetA.takeDamage(targetB.getATK());
    std::cout << "------------------------" << std::endl;
    targetA.attack("Charlie");
    targetC.takeDamage(targetA.getATK());
    std::cout << "------------------------" << std::endl;
    targetC.attack("Alice");
    targetA.takeDamage(targetC.getATK());
    std::cout << "------------------------" << std::endl;
    targetC.beRepaired(3);
    std::cout << "------------------------" << std::endl;
}
   
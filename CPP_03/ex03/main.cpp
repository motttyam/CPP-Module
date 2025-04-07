#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"

void printStatus(const DiamondTrap& dt) {
    std::cout << dt.getName() << " | HP: " << dt.getHP()
              << " | EP: " << dt.getEP()
              << " | ATK: " << dt.getATK() << std::endl;
}

int main() {
    DiamondTrap alice("Alice");
    DiamondTrap bob("Bob");
    DiamondTrap charlie("Charlie");

    std::cout << "\n==== Initial WhoAmI ====\n";
    alice.whoAmI();
    bob.whoAmI();
    charlie.whoAmI();

    std::cout << "\n==== Initial Status ====\n";
    printStatus(alice);
    printStatus(bob);
    printStatus(charlie);

    std::cout << "\n==== Alice attacks Bob ====\n";
    alice.attack("Bob");
    bob.takeDamage(alice.getATK());

    std::cout << "\n==== Bob repairs himself ====\n";
    bob.beRepaired(5);

    std::cout << "\n==== Bob attacks Alice ====\n";
    bob.attack("Alice");
    alice.takeDamage(bob.getATK());

    std::cout << "\n==== Alice attacks Charlie ====\n";
    alice.attack("Charlie");
    charlie.takeDamage(alice.getATK());

    std::cout << "\n==== Charlie attacks Alice ====\n";
    charlie.attack("Alice");
    alice.takeDamage(charlie.getATK());

    std::cout << "\n==== Charlie repairs himself ====\n";
    charlie.beRepaired(3);

    std::cout << "\n==== Final WhoAmI ====\n";
    charlie.whoAmI();

    std::cout << "\n==== Final Status ====\n";
    printStatus(alice);
    printStatus(bob);
    printStatus(charlie);

    std::cout << "\n==== End of Simulation ====\n";
    return (0);
}

   
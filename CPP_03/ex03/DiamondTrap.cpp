#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) 
:   ClapTrap(name + "_clap_name"),
    ScavTrap(name),
    FragTrap(name),
    _name(name)
{
    // 一時的にインスタンスを作成して、親クラスのコンストラクタを呼び出す
    // あんまり美しくないやり方な気はする
    ScavTrap ScavTrap(name);
    FragTrap FragTrap(name);
    
    // 仮作成したインスタンスを用いて追加していく
    this->setHP(FragTrap.getHP());
    this->setEP(ScavTrap.getEP());
    this->setATK(FragTrap.getATK());
    std::cout << "DiamondTrap constructor called for " << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
    std::cout << "Destroying DiamondTrap with " 
        << this->getHP() << " hit points, " 
        << this->getEP() << " energy points, and " 
        << this->getATK() << " attack damage." << std::endl;
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap Name is " << this->_name << std::endl;
    std::cout << "ClapTrap Name is " << ClapTrap::_name << std::endl;
}


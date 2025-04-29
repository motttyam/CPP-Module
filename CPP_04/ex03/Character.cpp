#include "Character.hpp"

Character::Character() : _name(""), _ground_i(0) {
    for (int i = 0; i < slotSize; i++) {
        this->_slots[i] = NULL;
    }
    for (int i = 0; i < groundSize; i++) {
        this->_grounds[i] = NULL;
    }
}

Character::Character(const std::string& name) : _name(name), _ground_i(0) {
    for (int i = 0; i < slotSize; i++) {
        this->_slots[i] = NULL;
    }
    for (int i = 0; i < groundSize; i++) {
        this->_grounds[i] = NULL;
    }
}

Character::Character(const Character& other) : _name(other.getName()), _ground_i(other.getGroundIndex()) {
    for (int i = 0; i < slotSize; i++) {
        if (other._slots[i])
            this->_slots[i] = other._slots[i]->clone();
        else
            this->_slots[i] = NULL;
    }
    for (int i = 0; i < groundSize; i++) {
        if (other._grounds[i])
            this->_grounds[i] = other._grounds[i]->clone();
        else
            this->_grounds[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        // コピー先のメモリを予め削除する
        for (int i = 0; i < slotSize; i++)
            if (this->_slots[i])
                delete this->_slots[i];
        for (int i = 0; i < groundSize; i++)
            if (this->_grounds[i])
                delete this->_grounds[i];

        // コピーを行う
        this->_name = other.getName();
        this->_ground_i = other.getGroundIndex();
        for (int i = 0; i < slotSize; i++) {
            if (other._slots[i])
                this->_slots[i] = other._slots[i]->clone();
            else
                this->_slots[i] = NULL;
        }
        for (int i = 0; i < groundSize; i++) {
            if (other._grounds[i])
                this->_grounds[i] = other._grounds[i]->clone();
            else
                this->_grounds[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character(){
    for (int i = 0; i < slotSize; i++) {
        if (this->_slots[i])
            delete this->_slots[i];
    }
    for (int i = 0; i < groundSize; i++) {
        if (this->_grounds[i])
            delete this->_grounds[i];
    }
}

// getter func
const std::string& Character::getName() const {
    return (_name);
}

const int& Character::getGroundIndex() const {
    return (_ground_i);
}

// public member func
void Character::equip(AMateria *m) {
    for (int i = 0; i < slotSize; i++) {
        if (!(this->_slots[i])) {
            _slots[i] = m;
            return ; 
        }
    }
    std::cout << "All slots are full. Please unequip a Materia before equipping a new one." << std::endl;
}

void Character::unequip(int idx) {
    // idxが不正な値だった場合
    if (idx < 0 || idx >= slotSize || !(this->_slots[idx])) {
        std::cerr << "error: Index is more than the slot size" << std::endl;
        return ;
    }
    
    // grounds(unequip先)が満杯だった時
    if (this->getGroundIndex() >= groundSize) {
        std::cerr << "error: fatal: Ground is full. Cannot unequip." << std::endl;
        return ;
    }
    this->_grounds[_ground_i++] = this->_slots[idx];
    this->_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    // idxが不正な値の場合は早期リターン
    if (idx < 0 || idx >= slotSize) {
        std::cerr << "error: Index is more than the slot size" << std::endl;
        return ;
    }

    // 指定されたslotにAMateriaが存在しない時
    if (!this->_slots[idx]) {
        std::cout << "No Materia in your slot" << std::endl;
        return ;
    }
    this->_slots[idx]->use(target);
}
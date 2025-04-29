#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < sourceSize; i++) {
        if (other.sources[i])
            this->sources[i] = other.sources[i]->clone();
        else
            this->sources[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        // コピー先のメモリを予め解放しておく
        for (int i = 0; i < sourceSize; i++)
            if (this->sources[i])
                delete this->sources[i];
        
        // コピーを行う
        for (int i = 0; i < sourceSize; i++) {
            if (other.sources[i])
                this->sources[i] = other.sources[i]->clone();
            else
                this->sources[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < sourceSize; i++)
            if (this->sources[i])
                delete this->sources[i];
}

// この関数はNULLチェックしないとあかんそう
void MateriaSource::learnMateria(AMateria* source){
    // NULLチェック
    if(!source) {
        std::cout << "Materia is not selected" << std::endl;
        return ;
    }
    
    // 空いているsource枠を探し、なければエラー文を表示する
    for (int i = 0; i < sourceSize; i++) {
        if (!this->sources[i]) {
            this->sources[i] = source;
            return ;
        }
    }
    std::cout << "MateriaSource is full. cannnot learn the Materia" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < sourceSize; i++) {
        if (this->sources[i] && this->sources[i]->getType() == type) {
            return (this->sources[i]->clone());    
        }
    }
    std::cout << "Cannot find the selected Materia. Please try again." << std::endl;
    return (NULL);
}
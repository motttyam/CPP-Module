#include "Brain.hpp"

Brain::Brain(){
    std::cout << "[Brain]Default Constrcutor called" << std::endl;
};

Brain::Brain(const Brain& other){

    // std::copy
    std::copy(other.ideas, other.ideas + IDEA_LENGTH, ideas);

    // これまでの42だとforを回しそう
    // for (int i = 0; i < IDEA_LENGTH; i++)
    //     Brain::ideas[i] = other.ideas[i];

    std::cout << "[Brain]Copy Constrcutor called" << std::endl;
};

Brain& Brain::operator=(const Brain& other) {
    // std::copy
    std::copy(other.ideas, other.ideas + IDEA_LENGTH, ideas);

    // これまでの42だとforを回しそう
    // for (int i = 0; i < IDEA_LENGTH; i++)
    //     Brain::ideas[i] = other.ideas[i];

    std::cout << "[Brain]Copy assignment operator called" << std::endl;
    return (*this);
}

Brain::~Brain(){
    std::cout << "[Brain]Destrcutor called" << std::endl;
}

// getter func
std::string Brain::getIdea(int index) const {
    // index のバリデーション
    if (index < 0 || index >= IDEA_LENGTH)
        return("");
    return (ideas[index]);
}

// setter func
void Brain::setIdea(int index, const std::string& idea) {
    // index のバリデーション
    if (index < 0 || index >= IDEA_LENGTH)
        return;
    ideas[index] = idea;
}

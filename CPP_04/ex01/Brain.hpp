#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <algorithm>

#define IDEA_LENGTH 100

class Brain {
    private:
        std::string ideas[IDEA_LENGTH];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};

#endif
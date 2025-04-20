#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <algorithm>

class Brain {
    private:
        static const int ideaLength = 100;
        std::string ideas[ideaLength];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};

#endif
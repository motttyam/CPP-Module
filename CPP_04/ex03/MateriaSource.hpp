#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define SOURCE_SIZE 4
class MateriaSource : public IMateriaSource {
    private:
        static const int sourceSize = 4;
        AMateria *sources[sourceSize];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        ~MateriaSource();
        void learnMateria(AMateria* source);
        AMateria* createMateria(const std::string& type);
};

#endif
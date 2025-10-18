#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include "Type.hpp"
#include <string>
#include <limits>

class Formatter {
    private:
        Formatter();
        Formatter(const Formatter& other);
        Formatter& operator=(const Formatter& other);
        ~Formatter();
    public:
        static void printFormatted(Parsed &p);
        static std::string formatChar(Parsed &p);
        static std::string formatInt(Parsed &p);
        static std::string formatFloat(Parsed &p);
        static std::string formatDouble(Parsed &p);
};

#endif
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
 
#include <string>
#include "Type.hpp"

class LiteralDetector;
class LiteralParser;

class ScalarConverter {
    private:
        //  Orthodox Canonical Form
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:
        static void convert(const std::string& l);

};

#endif
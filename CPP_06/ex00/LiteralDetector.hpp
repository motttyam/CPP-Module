#ifndef LITERAL_DETECTOR_HPP
#define LITERAL_DETECTOR_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

class LiteralDetector {
    private:
        LiteralDetector();
        LiteralDetector(const LiteralDetector& other);
        LiteralDetector& operator=(const LiteralDetector& other);
        ~LiteralDetector();
    public:
        static bool isPseudoFloat(const std::string& literal);
        static bool isPseudoDouble(const std::string& literal);
        static bool isCharLit(const std::string& literal);
        static bool isIntLit(const std::string& literal);
        static bool isFloatLit(const std::string& literal);
        static bool isDoubleLit(const std::string& literal);
        static size_t skipSign(const std::string& l);
        static bool allDigits(const std::string& l, size_t beg,  size_t end);

};

#endif
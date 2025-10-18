#include "Formatter.hpp"
#include <iostream>
#include <limits>
#include <climits>
#include <cctype>
#include <sstream>
#include <iomanip>


void Formatter::printFormatted(Parsed &p) {
    std::cout << "char: " << formatChar(p) << std::endl;
    std::cout << "int: " << formatInt(p) << std::endl;
    std::cout << "float: " << formatFloat(p) << std::endl;
    std::cout << "double: " << formatDouble(p) << std::endl;
}

std::string Formatter::formatChar(Parsed &p) {
    if (p.is_nan || p.inf_sign != 0)
        return ("impossible");

    //boundary check
    const double cmin = static_cast<double>(std::numeric_limits<char>::min());
    const double cmax = static_cast<double>(std::numeric_limits<char>::max());
    if (p.base < cmin || p.base > cmax)
        return "impossible";

    char c = static_cast<char>(p.base);
    if (!std::isprint(static_cast<unsigned char>(c)))
        return ("Non displayable");
    return ("'" + std::string(1, c) + "'");
}

std::string Formatter::formatInt(Parsed &p) {
    if (p.is_nan || p.inf_sign != 0)
        return ("impossible");
    if (p.base > INT_MAX || p.base < INT_MIN)
        return ("impossible");
    std::ostringstream oss;
    oss << static_cast<int>(p.base);

    return (oss.str());
}

std::string Formatter::formatFloat(Parsed &p) {
    if (p.is_nan)
        return ("nanf");
    if (p.inf_sign == 1)
        return ("+inff");
    if (p.inf_sign == -1)
        return ("-inff");

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << static_cast<float>(p.base);
    return (oss.str() + "f");
}

std::string Formatter::formatDouble(Parsed &p) {
    if (p.is_nan)
        return ("nan");
    if (p.inf_sign == 1)
        return ("+inf");
    if (p.inf_sign == -1)
        return ("-inf");
    
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << p.base;
    return (oss.str());
}



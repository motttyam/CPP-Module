#include "ScalarConverter.hpp"
#include "LiteralDetector.hpp"
#include "LiteralParser.hpp"
#include "Formatter.hpp"
#include "Type.hpp"
#include <cstdlib>   // strtod, strtol
#include <cerrno>    // errno, ERANGE
#include <cmath>     // std::isnan, std::isinf, std::fabs (C++98は <math.h> 相当)
#include <limits>    // numeric_limits
#include <climits>   // INT_MIN, INT_MAX

void ScalarConverter::convert(const std::string &l){
    Parsed p;
	Type type = LiteralDetector::detectType(l);
	if (!LiteralParser::parseToBase(l, type, p)){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	Formatter::printFormatted(p);
}

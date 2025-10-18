#include "LiteralParser.hpp"
#include "LiteralDetector.hpp"
#include <cstdlib>   // strtod, strtol
#include <cerrno>    // errno, ERANGE
#include <limits>    // numeric_limits
#include <climits>   // INT_MIN, INT_MAX

bool LiteralParser::parseToBase(const std::string& l, Type type, Parsed& out){
    out = Parsed();
    out.src = type;

    if (type == FLOAT_T && LiteralDetector::isPseudoFloat(l)){
        setPseudoFloat(l, out);
        return (true);
    }
    if (type == DOUBLE_T && LiteralDetector::isPseudoDouble(l)){
        setPseudoDouble(l, out);
        return (true);
    }

    if (type == CHAR_T)
        return (parseChar(l, out));
    if (type == INT_T)
        return (parseInt(l, out));
    if (type == FLOAT_T)
        return (parseFloat(l, out));
    if (type == DOUBLE_T)
        return (parseDouble(l, out));
    return (false);
}

void LiteralParser::setPseudoFloat(const std::string& l, Parsed& out){
	out.src = FLOAT_T;
	if (l == "nanf"){
		out.is_nan = true;
		out.base = std::numeric_limits<double>::quiet_NaN();
	}
	else if (l == "+inff"){
		out.inf_sign = 1;
		out.base = std::numeric_limits<double>::infinity();
	}
	else if (l == "-inff"){
		out.inf_sign = -1;
		out.base = -std::numeric_limits<double>::infinity();
	}
}

void LiteralParser::setPseudoDouble(const std::string& l, Parsed& out){
	out.src = DOUBLE_T;
	if (l == "nan"){
		out.is_nan = true;
		out.base = std::numeric_limits<double>::quiet_NaN();
	}
	else if (l == "+inf"){
		out.inf_sign = 1;
		out.base = std::numeric_limits<double>::infinity();
	}
	else if (l == "-inf"){
		out.inf_sign = -1;
		out.base = -std::numeric_limits<double>::infinity();
	}
}

bool LiteralParser::parseChar(const std::string& l, Parsed& out){
    if (l.size() != 1)
        return (false);
    char c = l[0]; // clarify literal can be converted to detected type
    out.from_char = true;
    out.base = static_cast<double>(c);
    return (true);
}

bool LiteralParser::parseInt(const std::string& l, Parsed& out){
    errno = 0;
    char *end = 0;
    long v = std::strtol(l.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE)
        return (false);
    if (v < INT_MIN || v > INT_MAX)
        return (false);
    int i = static_cast<int>(v); // clarify literal can be converted to detected type
    out.base = static_cast<double>(i);
    return (true);
}

bool LiteralParser::parseFloat(const std::string& l, Parsed& out){
    // f is already checked by detect type member func, but just in case
    if (l.size() < 4 || l[l.size() - 1] != 'f')
        return (false);

    errno = 0;
    char *end = 0;
    std::string core = l.substr(0, l.size() - 1);
    double d = std::strtod(core.c_str(), &end);
    if (*end != '\0' || errno == ERANGE)
        return (false);
    
    // float max / min check
    const double fmax = static_cast<double>(std::numeric_limits<float>::max());
    if (d > fmax || d < -fmax)
        return (false);
    
    float f = static_cast<float>(d);
    out.base = static_cast<double>(f);
    return (true);
}

bool LiteralParser::parseDouble(const std::string& l, Parsed& out){
    errno = 0;
    char *end = 0;
    double d = strtod(l.c_str(), &end);
    if (*end != '\0' || errno == ERANGE)
        return (false);
    out.base = d;
    return (true);
}
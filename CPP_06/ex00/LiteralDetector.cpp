#include "LiteralDetector.hpp"
#include "LiteralDetector.hpp"
#include <iostream>
#include <cctype>
#include <string>

bool LiteralDetector::isPseudoFloat(const std::string& literal){
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return (true);
    return (false);
}

bool LiteralDetector::isPseudoDouble(const std::string& literal){
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return (true);
    return (false);
}

bool LiteralDetector::isCharLit(const std::string& literal){
	return (literal.length() == 1 
        && std::isprint(static_cast<unsigned char>(literal[0])) 
        && !std::isdigit(static_cast<unsigned char>(literal[0])));
}

bool  LiteralDetector::isIntLit(const std::string& literal){
	size_t i = 0;
	size_t len = literal.length();

	i = skipSign(literal);
	if (!allDigits(literal, i, len))
			return (false);
	return (true);
}

bool  LiteralDetector::isFloatLit(const std::string& literal){
	
	size_t i = 0;
	size_t dot = literal.find('.');
	size_t lastDot = literal.rfind('.');
	size_t len = literal.length();
	size_t fracBeg = dot + 1;
	size_t fracEnd = len - 1;

	if (len < 4)
		return (false);
	if (literal[len - 1] != 'f')
		return (false);

	i = skipSign(literal);
	if (i >= len - 1)
		return (false);
	
	if (dot == std::string::npos || dot != lastDot)
		return (false);
			
	if (!allDigits(literal, i, dot))
		return (false);
	if (!allDigits(literal, fracBeg, fracEnd))
		return (false);
	return (true);
}

bool  LiteralDetector::isDoubleLit(const std::string& literal){
	
	size_t i = 0;
	size_t dot = literal.find('.');
	size_t lastDot = literal.rfind('.');
	size_t len = literal.length();
	size_t fracBeg = dot + 1;
	size_t fracEnd = len - 1;

	if (len < 4)
		return (false);
    if (literal[len - 1] == 'f')
        return (false);
	i = skipSign(literal);
	if (i >= len - 1)
		return (false);
	if (dot == std::string::npos || dot != lastDot)
		return (false);
	if (!allDigits(literal, i, dot))
		return (false);
	if (!allDigits(literal, fracBeg, fracEnd))
		return (false);
	return (true);
}

size_t LiteralDetector::skipSign(const std::string& l){
	if (!(l.empty()) && (l[0] == '+' || l[0] == '-'))
		return (1);
	return(0);	
}

bool LiteralDetector::allDigits(const std::string& l, size_t beg,  size_t end){
	if (beg >= end)
		return (false);
	for (size_t i = beg; i < end; ++i){
		if (!std::isdigit(static_cast<unsigned char>(l[i])))
			return (false);
	}
	return (true);
}
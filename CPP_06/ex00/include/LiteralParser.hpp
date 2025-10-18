#ifndef LITERALPARSER_HPP
#define LITERALPARSER_HPP

#include <string>
#include "Type.hpp"

class LiteralParser {
    private:
        LiteralParser();
        LiteralParser(const LiteralParser& other);
        LiteralParser& operator=(const LiteralParser& other);
        ~LiteralParser();
    public:
        static void setPseudoFloat(const std::string& l, Parsed& out);
        static void setPseudoDouble(const std::string& l, Parsed& out);
        static bool parseToBase(const std::string& l, Type type, Parsed& out);
        static bool parseChar(const std::string& l, Parsed& out);
        static bool parseInt(const std::string& l, Parsed& out);
        static bool parseFloat(const std::string& l, Parsed& out);
        static bool parseDouble(const std::string& l, Parsed& out);
};


#endif
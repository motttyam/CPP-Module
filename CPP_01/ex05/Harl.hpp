#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>

class Harl {
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        typedef void (Harl::*ptrHarlFunc)();
        std::map<std::string, ptrHarlFunc> levelComment;
    
    public:
        Harl();
        void complain(const std::string &level);
};

#endif

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define MAX_LEVEL 4

class Harl {
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        typedef void (Harl::*ptrHarlFunc)();
                typedef struct s_levelComment {
            std::string level;
            ptrHarlFunc harlFunc;
        } t_levelComment;
    
    public:
        Harl();
        void complain(const std::string &level);
        t_levelComment levelComments[MAX_LEVEL];

};

#endif

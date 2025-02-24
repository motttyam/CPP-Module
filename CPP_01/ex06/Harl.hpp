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
        std::map<std::string, int> levelPriority;
    
    public:
        Harl();
        void complain(const std::string &level);
        void complainFilter(const std::string &level);

};

#endif

// switch (expression) {
//     case constant1:
//         // コードブロック1
//         break;
//     case constant2:
//         // コードブロック2
//         break;
//     // 他のケース
//     default:
//         // デフォルトのコードブロック
// }
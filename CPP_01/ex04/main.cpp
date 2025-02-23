#include <iostream>
#include <fstream>
#include "Replace.hpp"

int main (int argc, char *argv[]){
    
    // 引数の数が正しいかどうか
    if (argc != 4){
        std::cerr << "The number of arguments is invalid" << std::endl;
        return (1);
    }

    Replace Replace(argv[1], argv[2], argv[3]);
    if (Replace.readFileContent() == true){
        Replace.createReplaceFile();
    }

    return (0);
}
#include <iostream>

int main(int argc, char *argv[])
{
    std::string arg;
    std::string space = " ";

    if (argc == 1){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (0);
    }
    
    for (int i = 1; i < argc;) {
        // ２回目以降であれば
        arg = arg + argv[i];
        i++;
    }
    for (unsigned long i = 0; i < arg.size(); i++){
        char c = toupper(arg[i]);
        std::cout << c;
    }
    return (0);
}
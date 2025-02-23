#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

class Replace {

    private:
        std::string _fileName;
        std::string _from;
        std::string _to;
        std::string _fileContent;
        const std::string &getFileName() const;
        const std::string &getFromString() const;
        const std::string &getToString() const;
        const std::string &getFileContent() const;

    public:
        Replace
        (
            const std::string &fileName,
            const std::string &from, 
            const std::string &to
        );
        ~Replace();
        bool readFileContent();
        void createReplaceFile();
        const std::string replaceFileContent();
};

#endif

// #include <fstream>
// #include <iostream>

// int main() {
//     std::ofstream outfile("example.txt");
//     if (!outfile) {
//         std::cerr << "File could not be created!" << std::endl;
//         return 1;
//     }

//     outfile << "Hello, World!" << std::endl;
//     outfile << "Writing to a file in C++" << std::endl;

//     outfile.close();
//     return 0;
// }

// #include <iostream>
// #include <string>

// std::string replaceString(
//     const std::string& subject, 
//     const std::string& search, 
//     const std::string& replace) 
// {
//     std::string result = subject;
//     std::size_t pos = 0;
//     while((pos = result.find(search, pos)) != std::string::npos) {
//         result.erase(pos, search.length());
//         result.insert(pos, replace);
//         pos += replace.length();
//     }
//     return result;
// }
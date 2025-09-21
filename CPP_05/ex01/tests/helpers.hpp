#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"


// C++98 でも使える簡易キャプチャ
struct CoutCapture {
    std::ostringstream oss;
    std::streambuf* prev;

    CoutCapture() : oss(), prev(std::cout.rdbuf(oss.rdbuf())) {}
    ~CoutCapture() { std::cout.rdbuf(prev); }

    std::string str() const { return oss.str(); }
};
// Print a section divider
void divider(const std::string& title);

#endif
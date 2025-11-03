#include "Iter.hpp"
#include <iostream>
#include <string>

// ======== テスト用関数群 ========

// 1. 書き換え系
void doubleValue(int &x) {
    x *= 2;
}

void toUpperChar(char &c) {
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

// 2. 出力系（const参照）
void printInt(const int &x) {
    std::cout << x << ' ';
}

void printChar(const char &c) {
    std::cout << c;
}

void printString(const std::string &s) {
    std::cout << s << ' ';
}

// =================================

int main() {
    std::cout << "=== Test 1: int array (modify + print) ===\n";
    int nums[] = {1, 2, 3, 4, 5};
    ::iter(nums, 5, doubleValue);
    ::iter(nums, 5, printInt);
    std::cout << "\n\n";

    std::cout << "=== Test 2: const int array (print only) ===\n";
    const int constNums[] = {10, 20, 30};
    ::iter(constNums, 3, printInt);
    std::cout << "\n\n";

    std::cout << "=== Test 3: char array (modify + print) ===\n";
    char letters[] = {'a', 'b', 'c', 'd'};
    ::iter(letters, 4, toUpperChar);
    ::iter(letters, 4, printChar);
    std::cout << "\n\n";

    std::cout << "=== Test 4: std::string array (print only) ===\n";
    std::string words[] = {"hello", "world", "iter", "template"};
    ::iter(words, 4, printString);
    std::cout << "\n";

    return 0;
}

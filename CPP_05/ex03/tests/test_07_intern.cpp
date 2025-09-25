// 目的: Intern::makeForm が正しいフォームを生成し、無効名では NULL を返すことを検証

#include <iostream>
#include <sstream>
#include "Intern.hpp"
#include "AForm.hpp"

static void test_valid_names() {
    std::cout << "=== test_valid_names ===" << std::endl;

    Intern intern;
    const char* names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; ++i) {
        std::ostringstream oss;
        oss << "Target_" << i; // C++98でもOK

        AForm* f = intern.makeForm(names[i], oss.str());
        if (f) {
            std::cout << "[OK] created: " << names[i] << std::endl;
            delete f; // 生成確認だけなので解放
        } else {
            std::cout << "[NG] failed to create: " << names[i] << std::endl;
        }
    }
    std::cout << std::endl;
}

static void test_invalid_names() {
    std::cout << "=== test_invalid_names ===" << std::endl;

    Intern intern;
    const char* invalids[] = {
        "invalid form",
        "robotomy",                 // 一部一致はNG
        "presidential",             // 一部一致はNG
        " robotomy request",        // 先頭に空白
        "robotomy request ",        // 末尾に空白
        "Robotomy Request",         // 大文字小文字違い
        "shrubbery  creation",      // 余計なスペース
        ""                          // 空文字
    };

    const size_t N = sizeof(invalids) / sizeof(invalids[0]);
    for (size_t i = 0; i < N; ++i) {
        AForm* f = intern.makeForm(invalids[i], "Nobody");
        if (f == NULL) {
            std::cout << "[OK] invalid returned NULL: \"" << invalids[i] << "\"" << std::endl;
        } else {
            std::cout << "[NG] should be NULL but created for: \"" << invalids[i] << "\"" << std::endl;
            delete f; // 念のため解放
        }
    }
    std::cout << std::endl;
}

int main() {
    test_valid_names();
    test_invalid_names();
    return 0;
}

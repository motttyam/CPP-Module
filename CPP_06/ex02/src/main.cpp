#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

static void test_one(const char* label) {
    Base* p = generate();
    std::cout << label << "(identify *): ";
    identify(p);
    std::cout << label << "(identify &): ";
    identify(*p);
    std::cout << std::endl;
    delete p;
}

int main () {
    test_one("p1");
    test_one("p2");
    test_one("p3");
    test_one("p4");

    // NULL テスト（参照版は呼ばない！）
    Base* pnull = 0;
    std::cout << "NULL(identify *): ";
    identify(pnull);
    std::cout << "NULL(identify &): ";
    std::cout << "skip (cannot bind reference to NULL)" << std::endl;


    return (0);
}
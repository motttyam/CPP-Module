#include "LiteralDetector.hpp"
#include "Type.hpp"
#include "helpers.hpp"
#include <string>

static void check(const std::string& lit, Type expected, const std::string& name) {
    Type t = LiteralDetector::detectType(lit);
    expect_true(t == expected, "detectType(\"" + lit + "\") -> " + name);
}

int main() {
    // pseudo
    check("nanf",  FLOAT_T,  "FLOAT_T (pseudo)");
    check("+inff", FLOAT_T,  "FLOAT_T (pseudo)");
    check("-inff", FLOAT_T,  "FLOAT_T (pseudo)");
    check("nan",   DOUBLE_T, "DOUBLE_T (pseudo)");
    check("+inf",  DOUBLE_T, "DOUBLE_T (pseudo)");
    check("-inf",  DOUBLE_T, "DOUBLE_T (pseudo)");

    // char
    check("a",     CHAR_T,   "CHAR_T");
    check("Z",     CHAR_T,   "CHAR_T");
    check("0",     INT_T,    "INT_T (not CHAR_T)"); // 数字1文字はint扱い

    // int
    check("0",     INT_T,    "INT_T");
    check("-42",   INT_T,    "INT_T");
    check("+7",    INT_T,    "INT_T");

    // float
    check("4.2f",  FLOAT_T,  "FLOAT_T");
    check("-0.0f", FLOAT_T,  "FLOAT_T");

    // double
    check("4.2",   DOUBLE_T, "DOUBLE_T");
    check("-0.0",  DOUBLE_T, "DOUBLE_T");

    // invalid
    expect_true(LiteralDetector::detectType("++1") == UNKNOWN_T, "invalid ++1");
    expect_true(LiteralDetector::detectType("1f")  == UNKNOWN_T, "invalid 1f");

    // 非許容（仕様外やフォーマット不正）
    expect_true(LiteralDetector::detectType("inf")  == UNKNOWN_T, "invalid: 'inf' (not in spec)");
    expect_true(LiteralDetector::detectType("inff") == UNKNOWN_T, "invalid: 'inff' (not in spec)");
    expect_true(LiteralDetector::detectType("1e10") == UNKNOWN_T, "invalid: scientific notation");
    expect_true(LiteralDetector::detectType("42.")  == UNKNOWN_T, "invalid: trailing dot");
    expect_true(LiteralDetector::detectType(".42")  == UNKNOWN_T, "invalid: leading dot");
    expect_true(LiteralDetector::detectType(" 42")  == UNKNOWN_T, "invalid: leading space");
    expect_true(LiteralDetector::detectType("42 ")  == UNKNOWN_T, "invalid: trailing space");


    print_summary();
    return g_stats.failed == 0 ? 0 : 1;
}

#include "LiteralParser.hpp"
#include "LiteralDetector.hpp"
#include "Type.hpp"
#include "helpers.hpp"
#include <string>
#include <cmath>
#include <limits>
#include <climits>

int main() {
    Parsed p;

    // pseudo float/double
    expect_true(LiteralParser::parseToBase("nanf", FLOAT_T, p), "parseToBase(nanf)");
    expect_true(p.is_nan, "nanf -> is_nan");

    expect_true(LiteralParser::parseToBase("+inff", FLOAT_T, p), "parseToBase(+inff)");
    expect_true(p.inf_sign == 1, "+inff -> +inf");

    expect_true(LiteralParser::parseToBase("-inf", DOUBLE_T, p), "parseToBase(-inf)");
    expect_true(p.inf_sign == -1, "-inf -> -inf");

    // char
    expect_true(LiteralParser::parseToBase("A", CHAR_T, p), "parseToBase('A')");
    expect_true(p.from_char == true, "from_char flag");
    expect_true(static_cast<int>(p.base) == static_cast<int>('A'), "base == 'A'");

    // int
    expect_true(LiteralParser::parseToBase("42", INT_T, p), "parseToBase(42)");
    expect_true(static_cast<int>(p.base) == 42, "base==42");

    // float
    expect_true(LiteralParser::parseToBase("4.2f", FLOAT_T, p), "parseToBase(4.2f)");
    // もともと: expect_true(static_cast<int>(p.base*10) == 42, "base~=4.2");
    expect_near(p.base, 4.2, 1e-4, "base~=4.2 (float cast stored as double)");

    // double
    expect_true(LiteralParser::parseToBase("4.2", DOUBLE_T, p), "parseToBase(4.2)");
    // もともと: expect_true(static_cast<int>(p.base*10) == 42, "base~=4.2");
    expect_near(p.base, 4.2, 1e-9, "base~=4.2 (double)");


    // invalids
    expect_true(!LiteralParser::parseToBase("++1", INT_T, p), "invalid ++1");
    expect_true(!LiteralParser::parseToBase("1f", FLOAT_T, p), "invalid 1f");

    // int 境界
    expect_true(LiteralParser::parseToBase("2147483647", INT_T, p), "INT_MAX ok");
    expect_true(LiteralParser::parseToBase("-2147483648", INT_T, p), "INT_MIN ok");
    expect_true(!LiteralParser::parseToBase("2147483648", INT_T, p), "INT_MAX+1 fail");
    expect_true(!LiteralParser::parseToBase("-2147483649", INT_T, p), "INT_MIN-1 fail");

    // float 境界（小数で十進表記かつ max 近傍）
    expect_true(LiteralParser::parseToBase("340282300000000000000000000000000000000.0f", FLOAT_T, p),
                "near float max ok");
    expect_true(!LiteralParser::parseToBase("999999999999999999999999999999999999999.9f", FLOAT_T, p),
                "beyond float max fail");

    print_summary();
    return g_stats.failed == 0 ? 0 : 1;
}

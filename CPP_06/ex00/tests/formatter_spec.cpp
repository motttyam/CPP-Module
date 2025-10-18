// tests/formatter_spec.cpp
#include "Formatter.hpp"
#include "helpers.hpp"
#include <limits>
#include <string>
#include <climits>

// Parsed の初期化ユーティリティ
static Parsed P() { Parsed x; return x; }

int main() {
    // 0（基本形）
    {
        Parsed p = P();
        p.base = 0.0;
        expect_eq_str(Formatter::formatInt(p), "0", "int: 0");
        expect_eq_str(Formatter::formatFloat(p), "0.0f", "float: 0.0f");
        expect_eq_str(Formatter::formatDouble(p), "0.0", "double: 0.0");
        expect_eq_str(Formatter::formatChar(p), "Non displayable", "char: Non displayable");
    }

    // 表示可能/不可能の境界（char）
    {
        Parsed p = P();
        p.base = 31.0;
        expect_eq_str(Formatter::formatChar(p), "Non displayable", "char: 31 -> Non displayable");
        p.base = 32.0;
        expect_eq_str(Formatter::formatChar(p), "' '", "char: 32 -> ' '");
        p.base = 126.0;
        expect_eq_str(Formatter::formatChar(p), "'~'", "char: 126 -> '~'");
        p.base = 127.0;
        expect_eq_str(Formatter::formatChar(p), "Non displayable", "char: 127 -> Non displayable");
    }

    // '*' が表示されるケース
    {
        Parsed p = P();
        p.base = static_cast<double>('*'); // 42
        expect_eq_str(Formatter::formatChar(p), "'*'", "char: '*'");
    }

    // 疑似リテラル
    {
        Parsed p = P();
        p.is_nan = true;
        expect_eq_str(Formatter::formatInt(p), "impossible", "int: impossible (nan)");
        expect_eq_str(Formatter::formatFloat(p), "nanf", "float: nanf");
        expect_eq_str(Formatter::formatDouble(p), "nan", "double: nan");
    }
    {
        Parsed p = P();
        p.inf_sign = 1;
        expect_eq_str(Formatter::formatInt(p), "impossible", "int: impossible (+inf)");
        expect_eq_str(Formatter::formatFloat(p), "+inff", "float: +inff");
        expect_eq_str(Formatter::formatDouble(p), "+inf", "double: +inf");
    }
    {
        Parsed p = P();
        p.inf_sign = -1;
        expect_eq_str(Formatter::formatInt(p), "impossible", "int: impossible (-inf)");
        expect_eq_str(Formatter::formatFloat(p), "-inff", "float: -inff");
        expect_eq_str(Formatter::formatDouble(p), "-inf", "double: -inf");
    }

    // int の範囲と境界
    {
        Parsed p = P();
        p.base = static_cast<double>(INT_MAX);
        expect_eq_str(Formatter::formatInt(p), "2147483647", "int: INT_MAX");
        p.base = static_cast<double>(INT_MIN);
        expect_eq_str(Formatter::formatInt(p), "-2147483648", "int: INT_MIN");

        p.base = static_cast<double>(INT_MAX) + 1.0;
        expect_eq_str(Formatter::formatInt(p), "impossible", "int: overflow -> impossible");
        p.base = static_cast<double>(INT_MIN) - 1.0;
        expect_eq_str(Formatter::formatInt(p), "impossible", "int: underflow -> impossible");
    }

    // char の範囲外
    {
        Parsed p = P();
        p.base = static_cast<double>(std::numeric_limits<unsigned char>::max()) + 10.0;
        expect_eq_str(Formatter::formatChar(p), "impossible", "char: overflow -> impossible");
        p.base = -999.0;
        expect_eq_str(Formatter::formatChar(p), "impossible", "char: underflow -> impossible");
    }

    // 丸めと表記（1桁固定）
    {
        Parsed p = P();
        p.base = 2.3;
        expect_eq_str(Formatter::formatDouble(p), "2.3", "double: 2.3");
        expect_eq_str(Formatter::formatFloat(p),  "2.3f", "float: 2.3f");

        p.base = -42.3;
        expect_eq_str(Formatter::formatDouble(p), "-42.3", "double: -42.3");
        expect_eq_str(Formatter::formatFloat(p),  "-42.3f", "float: -42.3f");

        p.base = 2.0;
        expect_eq_str(Formatter::formatDouble(p), "2.0", "double: 2.0");
        expect_eq_str(Formatter::formatFloat(p),  "2.0f", "float: 2.0f");
    }

    // 負のゼロ（実装依存でどちらでもOK）
    {
        Parsed p = P();
        p.base = -0.0;
        std::string df = Formatter::formatDouble(p);
        std::string ff = Formatter::formatFloat(p);
        expect_true(df == "0.0" || df == "-0.0", "double: +/-0.0 表示");
        expect_true(ff == "0.0f" || ff == "-0.0f", "float: +/-0.0f 表示");
    }

    // 大きめの数（指数表記にならないこと）
    {
        Parsed p = P();
        p.base = 1000000.0;
        expect_eq_str(Formatter::formatDouble(p), "1000000.0", "double: 1e6 -> 1000000.0");
        expect_eq_str(Formatter::formatFloat(p),  "1000000.0f", "float: 1e6 -> 1000000.0f");
    }

    print_summary();
    return g_stats.failed == 0 ? 0 : 1;
}

// tests/scalar_converter_spec.cpp
#include "ScalarConverter.hpp"
#include "helpers.hpp"
#include <iostream>
#include <sstream>
#include <string>

// C++98対応のstdoutキャプチャ（helpers.hppにあるtemplate版を使用）
static void callPInf(){ ScalarConverter::convert("+inf"); }   // double擬似
static void callNInfF(){ ScalarConverter::convert("-inff"); } // float擬似
static void callNegZeroF(){ ScalarConverter::convert("-0.0f"); }
static void callBad(){ ScalarConverter::convert("42."); }
static void call0(){ ScalarConverter::convert("0"); }
static void callNan(){ ScalarConverter::convert("nan"); }
static void callF(){ ScalarConverter::convert("42.0f"); }

int main() {
    // PDFの例（0 / nan / 42.0f）
    {
        std::string out = capture_stdout(&call0);
        expect_eq_str(out,
            "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n",
            "convert(\"0\") example");
    }
    {
        std::string out = capture_stdout(&callNan);
        expect_eq_str(out,
            "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n",
            "convert(\"nan\") example");
    }
    {
        std::string out = capture_stdout(&callF);
        expect_eq_str(out,
            "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n",
            "convert(\"42.0f\") example");
    }

    // 擬似と不正
    {
        std::string out = capture_stdout(&callPInf);
        expect_eq_str(out,
            "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n",
            "convert(\"+inf\")");
    }
    {
        std::string out = capture_stdout(&callNInfF);
        expect_eq_str(out,
            "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n",
            "convert(\"-inff\")");
    }
    {
        std::string out = capture_stdout(&callBad);
        expect_eq_str(out,
            "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n",
            "invalid literal -> all impossible");
    }

    // -0.0f は環境差が出るため厳密比較は避ける
    {
        std::string out = capture_stdout(&callNegZeroF);
        expect_true(out.find("float: 0.0f") != std::string::npos ||
                    out.find("float: -0.0f") != std::string::npos, "-0.0f float line");
        expect_true(out.find("double: 0.0") != std::string::npos ||
                    out.find("double: -0.0") != std::string::npos, "-0.0 double line");
    }

    print_summary();
    return g_stats.failed == 0 ? 0 : 1;
}

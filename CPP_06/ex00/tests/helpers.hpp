#pragma once
#include <string>
#include <iostream>
#include <sstream>

struct TestStats {
    int passed;
    int failed;
    TestStats(): passed(0), failed(0) {}
};

extern TestStats g_stats;

inline void expect_true(bool cond, const std::string& msg) {
    if (cond) { g_stats.passed++; }
    else {
        g_stats.failed++;
        std::cerr << "[FAIL] " << msg << std::endl;
    }
}

inline void expect_eq_str(const std::string& a, const std::string& b, const std::string& msg) {
    if (a == b) { g_stats.passed++; }
    else {
        g_stats.failed++;
        std::cerr << "[FAIL] " << msg << "\n  got:    [" << a << "]\n  expect: [" << b << "]\n";
    }
}

inline void expect_near(double a, double b, double eps, const std::string& msg) {
    double diff = a - b;
    if (diff < 0) diff = -diff;
    if (diff <= eps) { g_stats.passed++; }
    else {
        g_stats.failed++;
        std::cerr << "[FAIL] " << msg << "\n  got: " << a << "\n  expect: " << b
                  << " (eps=" << eps << ")\n";
    }
}


inline void print_summary() {
    std::cout << "[SUMMARY] passed=" << g_stats.passed
              << " failed=" << g_stats.failed << std::endl;
}

// stdout を一時的に差し替えてキャプチャ
template <typename F>
std::string capture_stdout(F fn) {
    std::streambuf* old = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    fn();
    std::cout.rdbuf(old);
    return oss.str();
}

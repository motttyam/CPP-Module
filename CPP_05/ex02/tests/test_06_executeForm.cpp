#include "helpers.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ユーティリティ
static bool contains(const std::string& s, const std::string& sub) {
    return s.find(sub) != std::string::npos;
}

static bool checkOutput(const std::string& out,
                        const std::string& caseName,
                        const std::string& must1,
                        const std::string& must2,
                        const std::string& must3) {
    std::cerr << "[Captured] " << out;
    if (!contains(out, must1) || !contains(out, must2) || !contains(out, must3)) {
        std::cerr << "❌ " << caseName << " FAILED" << std::endl;
        return false;
    }
    std::cerr << "✅ " << caseName << " PASSED" << std::endl;
    return true;
}

int main() {
    divider("Bureaucrat::executeForm messages");

    bool allOk = true;

    Bureaucrat boss("Boss", 1);       // 最上位
    Bureaucrat mid("Mid", 100);       // 中堅
    Bureaucrat low("Low", 150);       // 最下位

    // --- 未署名フォームの実行（失敗） ---
    {
        ShrubberyCreationForm shrub("garden");
        CoutCapture cap;
        boss.executeForm(shrub);
        allOk &= checkOutput(cap.str(),
                             "Failure case (unsigned form)",
                             "Boss", "couldn", "ShrubberyCreationForm");
    }

    // --- 実行グレード不足（失敗） ---
    {
        ShrubberyCreationForm shrub("home"); // sign 145, exec 137
        mid.signForm(shrub);                 // mid=100 → 署名はできる
        CoutCapture cap;
        low.executeForm(shrub);              // low=150 → 実行不可
        allOk &= checkOutput(cap.str(),
                             "Failure case (exec grade too low)",
                             "Low", "couldn", "ShrubberyCreationForm");
    }

    // --- 成功ケース（Shrubbery） ---
    {
        ShrubberyCreationForm shrub("park");
        boss.signForm(shrub);
        CoutCapture cap;
        boss.executeForm(shrub);
        allOk &= checkOutput(cap.str(),
                             "Success case (Shrubbery executed)",
                             "Boss", "executed", "ShrubberyCreationForm");
    }

    // --- 成功ケース（Robotomy） ---
    {
        RobotomyRequestForm robo("Bender");
        boss.signForm(robo);
        CoutCapture cap;
        boss.executeForm(robo);
        allOk &= checkOutput(cap.str(),
                             "Success case (Robotomy executed)",
                             "Boss", "executed", "RobotomyRequestForm");
    }

    // --- 成功ケース（Presidential Pardon） ---
    {
        PresidentialPardonForm pardon("Ford");
        boss.signForm(pardon);
        CoutCapture cap;
        boss.executeForm(pardon);
        allOk &= checkOutput(cap.str(),
                             "Success case (Pardon executed)",
                             "Boss", "executed", "PresidentialPardonForm");
    }

    if (allOk) {
        std::cerr << "🎉 All executeForm tests PASSED" << std::endl;
        return 0;
    } else {
        std::cerr << "⚠️ Some executeForm tests FAILED" << std::endl;
        return 1;
    }
}

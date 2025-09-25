#include "helpers.hpp"
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ====== ユーティリティ ======
static bool contains(const std::string& s, const std::string& sub) {
    return s.find(sub) != std::string::npos;
}

static bool checkOutput(const std::string& out,
                        const std::string& caseName,
                        const std::string& must1,
                        const std::string& must2,
                        const std::string& must3) {
    std::cerr << "[Captured] " << out;  // ← キャプチャ内容をstderrに出す
    if (!contains(out, must1) || !contains(out, must2) || !contains(out, must3)) {
        std::cerr << "❌ " << caseName << " FAILED" << std::endl;
        return false;
    }
    std::cerr << "✅ " << caseName << " PASSED" << std::endl;
    return true;
}

int main() {
    divider("Bureaucrat::signForm messages (multiple cases)");

    bool allOk = true;

    Bureaucrat high("HighRank", 5);
    Bureaucrat mid("MidRank", 75);
    Bureaucrat low("LowRank", 150);

    ShrubberyCreationForm shrub("Garden");   // sign 145
    RobotomyRequestForm   robo("Bender");    // sign 72
    PresidentialPardonForm pardon("Ford");   // sign 25

    // --- 成功ケース ---
    {
        CoutCapture cap;
        high.signForm(robo);
        allOk &= checkOutput(cap.str(),
                             "Success case (high -> Robotomy)",
                             "HighRank", "signed", "RobotomyRequestForm");
    }
    {
        CoutCapture cap;
        mid.signForm(shrub);
        allOk &= checkOutput(cap.str(),
                             "Success case (mid -> Shrubbery)",
                             "MidRank", "signed", "ShrubberyCreationForm");
    }
    {
        CoutCapture cap;
        high.signForm(pardon);
        allOk &= checkOutput(cap.str(),
                             "Success case (high -> Pardon)",
                             "HighRank", "signed", "PresidentialPardonForm");
    }

    // --- 失敗ケース ---
    {
        CoutCapture cap;
        low.signForm(shrub);
        allOk &= checkOutput(cap.str(),
                             "Failure case (low -> Shrubbery)",
                             "LowRank", "couldn", "ShrubberyCreationForm");
    }
    {
        CoutCapture cap;
        mid.signForm(pardon);
        allOk &= checkOutput(cap.str(),
                             "Failure case (mid -> Pardon)",
                             "MidRank", "couldn", "PresidentialPardonForm");
    }

    // --- 再署名ケース ---
    {
        RobotomyRequestForm once("Unit42");
        Bureaucrat exec("Executor", 1);

        CoutCapture cap1;
        exec.signForm(once);
        allOk &= checkOutput(cap1.str(),
                             "Success case (first sign)",
                             "Executor", "signed", "RobotomyRequestForm");

        CoutCapture cap2;
        exec.signForm(once);
        allOk &= checkOutput(cap2.str(),
                             "Success case (re-sign)",
                             "Executor", "signed", "RobotomyRequestForm");
    }

    if (allOk) {
        std::cerr << "🎉 All signForm tests PASSED" << std::endl;
        return 0;
    } else {
        std::cerr << "⚠️ Some signForm tests FAILED" << std::endl;
        return 1;
    }
}

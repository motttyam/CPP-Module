#include "helpers.hpp"
#include <iostream>
#include <string>

// ====== ユーティリティ ======
static bool contains(const std::string& s, const std::string& sub) {
    return s.find(sub) != std::string::npos;
}

static bool checkOutput(const std::string& out,
                        const std::string& caseName,
                        const std::string& must1,
                        const std::string& must2,
                        const std::string& must3) {
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

    // Fixture
    Bureaucrat high("HighRank", 5);        // 強い権限
    Bureaucrat mid("MidRank", 75);         // 中くらい
    Bureaucrat low("LowRank", 150);        // 一番下

    Form formHigh("TopSecret", 1, 1);      // サインに等級=1が必要
    Form formMid("Budget", 75, 50);        // サインに等級=75が必要
    Form formLow("Residency", 150, 150);   // 誰でもサイン可

    // --- 成功ケース ---
    {
        CoutCapture cap;
        high.signForm(formMid); // 5 <= 75 OK
        allOk &= checkOutput(cap.str(),
                             "Success case (high->mid)",
                             "HighRank", "signed", "Budget");
    }
    {
        CoutCapture cap;
        mid.signForm(formMid); // 75 == 75 OK
        allOk &= checkOutput(cap.str(),
                             "Success case (mid->mid)",
                             "MidRank", "signed", "Budget");
    }
    {
        CoutCapture cap;
        low.signForm(formLow); // 150 == 150 OK
        allOk &= checkOutput(cap.str(),
                             "Success case (low->low)",
                             "LowRank", "signed", "Residency");
    }

    // --- 失敗ケース（等級不足） ---
    {
        CoutCapture cap;
        low.signForm(formMid); // 150 > 75 -> 署名不可
        allOk &= checkOutput(cap.str(),
                             "Failure case (low->mid)",
                             "LowRank", "couldn", "Budget");
    }
    {
        CoutCapture cap;
        mid.signForm(formHigh); // 75 > 1 -> 署名不可
        allOk &= checkOutput(cap.str(),
                             "Failure case (mid->high)",
                             "MidRank", "couldn", "TopSecret");
    }

    // --- 再署名ケース（成功扱い） ---
    {
        Form formOnce("PassportApplication", 30, 20);
        Bureaucrat counselor("Counselor", 30);

        CoutCapture cap1;
        counselor.signForm(formOnce); // 1回目
        allOk &= checkOutput(cap1.str(),
                             "Success case (first sign)",
                             "Counselor", "signed", "PassportApplication");

        CoutCapture cap2;
        counselor.signForm(formOnce); // 2回目（再署名も「signed」出力を期待）
        allOk &= checkOutput(cap2.str(),
                             "Success case (re-sign)",
                             "Counselor", "signed", "PassportApplication");
    }

    if (allOk) {
        std::cerr << "🎉 All signForm tests PASSED" << std::endl;
        return 0;
    } else {
        std::cerr << "⚠️ Some signForm tests FAILED" << std::endl;
        return 1;
    }
}

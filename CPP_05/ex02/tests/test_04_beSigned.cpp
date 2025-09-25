// tests/test_04_beSigned.cpp
#include "helpers.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void mustSign(Bureaucrat& b, AForm& f) {
    std::cout << "[EXPECT SUCCESS] " << b.getName()
              << " (grade " << b.getGrade() << ")"
              << " -> Form: " << f.getFormName() << std::endl;
    try {
        f.beSigned(b);
        if (f.getIsSigned()) {
            std::cout << "✅ Form is signed" << std::endl;
        } else {
            std::cout << "❌ Form is NOT signed (unexpected)" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "❌ Unexpected exception: " << e.what() << std::endl;
    }
}

static void mustFailToSign(Bureaucrat& b, AForm& f) {
    std::cout << "[EXPECT FAILURE] " << b.getName()
              << " (grade " << b.getGrade() << ")"
              << " -> Form: " << f.getFormName() << std::endl;
    try {
        f.beSigned(b);
        std::cout << "❌ Unexpected SUCCESS (should have thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✅ Exception caught as expected: " << e.what() << std::endl;
    }
}

int main() {
    divider("AForm::beSigned behavior");

    // 署名できる人/できない人
    Bureaucrat counselor("Counselor", 30); // ロボトミー(72)やシュラブ(145)に十分
    Bureaucrat clerk("Clerk", 150);        // ほぼ不可

    // テスト対象フォーム
    RobotomyRequestForm robo("Bender");      // sign 72,  exec 45
    ShrubberyCreationForm shrub("garden");   // sign 145, exec 137
    PresidentialPardonForm pardon("Ford");   // sign 25,  exec 5

    // --- 成功ケース（十分な等級で署名できる）---
    mustSign(counselor, robo);   // 30 <= 72 -> OK
    mustSign(counselor, shrub);  // 30 <= 145 -> OK

    // --- 再署名ケース（挙動は実装依存：例外でも非例外でも可）---
    std::cout << "[Re-sign attempt] " << counselor.getName()
              << " tries to sign " << robo.getFormName() << " again." << std::endl;
    try {
        robo.beSigned(counselor);
        std::cout << "ℹ️ Re-sign did not throw (implementation dependent)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "ℹ️ Exception on re-sign: " << e.what() << std::endl;
    }

    // --- 失敗ケース（等級不足で署名できない）---
    mustFailToSign(clerk, shrub);   // 150 > 145 -> 失敗
    mustFailToSign(clerk, pardon);  // 150 > 25  -> 失敗

    std::cout << "beSigned tests finished.\n";
    return 0;
}

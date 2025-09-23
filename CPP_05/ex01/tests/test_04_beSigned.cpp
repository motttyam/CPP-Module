#include "helpers.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void mustSign(Bureaucrat& b, Form& f) {
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
    } catch (std::exception& e) {
        std::cout << "❌ Unexpected exception: " << e.what() << std::endl;
    }
}

static void mustFailToSign(Bureaucrat& b, Form& f) {
    std::cout << "[EXPECT FAILURE] " << b.getName()
              << " (grade " << b.getGrade() << ")"
              << " -> Form: " << f.getFormName() << std::endl;
    try {
        f.beSigned(b);
        std::cout << "❌ Unexpected SUCCESS (should have thrown)" << std::endl;
    } catch (std::exception& e) {
        std::cout << "✅ Exception caught as expected: " << e.what() << std::endl;
    }
}

int main() {
    divider("Form::beSigned behavior");

    Bureaucrat counselor("Counselor", 30);
    Bureaucrat clerk("Clerk", 150);

    Form passport("PassportApplication", 30, 20);
    Form tax("TaxReturn", 75, 75);

    // 成功ケース
    mustSign(counselor, passport);

    // 再署名ケース
    std::cout << "[Re-sign attempt] " << counselor.getName()
              << " tries to sign " << passport.getFormName() << " again." << std::endl;
    try {
        passport.beSigned(counselor);
        std::cout << "ℹ️ Re-sign did not throw (implementation dependent)" << std::endl;
    } catch (std::exception& e) {
        std::cout << "ℹ️ Exception on re-sign: " << e.what() << std::endl;
    }

    // 失敗ケース
    mustFailToSign(clerk, tax);

    std::cout << "beSigned tests finished.\n";
    return 0;
}

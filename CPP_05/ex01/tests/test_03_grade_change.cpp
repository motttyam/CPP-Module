#include "helpers.hpp"
#include "Bureaucrat.hpp"

int main() {
    divider("incrementGrade / decrementGrade responsibility");

    // --- increment の正常動作 ---
    Bureaucrat mid("Mid", 75);
    std::cout << "Initial grade: " << mid.getGrade() << std::endl;
    mid.incrementGrade(); // 74になるはず
    std::cout << "After increment: " << mid.getGrade() << std::endl;

    // --- decrement の正常動作 ---
    mid.decrementGrade(); // 元に戻るはず
    std::cout << "After decrement: " << mid.getGrade() << std::endl;

    // --- increment の境界チェック (grade 1から) ---
    Bureaucrat top("Top", 1);
    std::cout << "[Boundary check] " << top.getName()
              << " current grade = " << top.getGrade()
              << " -> try incrementGrade()" << std::endl;
    try {
        top.incrementGrade(); // これ以上上げられない → 例外
        std::cout << "❌ No exception at incrementing from grade 1\n";
        return 1;
    } catch (std::exception& e) {
        std::cout << "✅ Exception at incrementing from grade 1: "
                  << e.what() << std::endl;
    }

    // --- decrement の境界チェック (grade 150から) ---
    Bureaucrat low("Low", 150);
    std::cout << "[Boundary check] " << low.getName()
              << " current grade = " << low.getGrade()
              << " -> try decrementGrade()" << std::endl;
    try {
        low.decrementGrade(); // これ以上下げられない → 例外
        std::cout << "❌ No exception at decrementing from grade 150\n";
        return 1;
    } catch (std::exception& e) {
        std::cout << "✅ Exception at decrementing from grade 150: "
                  << e.what() << std::endl;
    }

    std::cout << "Grade change tests finished.\n";
    return 0;
}

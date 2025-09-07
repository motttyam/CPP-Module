#include "Bureaucrat.hpp"

// 一覧を表示
void printBureaucratList(const Bureaucrat& intern,
                         const Bureaucrat& junior,
                         const Bureaucrat& sophomore,
                         const Bureaucrat& senior,
                         const Bureaucrat& manager,
                         const Bureaucrat& director,
                         const Bureaucrat& ceo)
{
    std::cout << "=== Bureaucrat List ===\n";
    std::cout << intern   << '\n'
              << junior   << '\n'
              << sophomore<< '\n'
              << senior   << '\n'
              << manager  << '\n'
              << director << '\n'
              << ceo      << '\n';
}

// 正常系：increment / decrement を確認（例外は出ない想定）
void testNormalIncDec(Bureaucrat& manager, Bureaucrat& junior)
{
    std::cout << "\n=== Increment/Decrement Test (Normal) ===\n";
    try {
        std::cout << "Before increment: " << manager << '\n';
        manager.incrementGrade();
        std::cout << "After  increment: " << manager << '\n';

        std::cout << "Before decrement: " << junior << '\n';
        junior.decrementGrade();
        std::cout << "After  decrement: " << junior << '\n';
    } catch (std::exception& e) {
        std::cerr << "Exception (normal inc/dec): " << e.what() << '\n';
    }
}

// 例外系：コンストラクタの範囲外（0, 151）で例外が投げられるか
void testConstructorExceptions()
{
    std::cout << "\n=== Constructor Exception Test ===\n";
    try {
        Bureaucrat tooHigh("TooHigh", 0);
        (void)tooHigh;
    } catch (std::exception& e) {
        std::cerr << "Exception caught (grade 0): " << e.what() << '\n';
    }

    try {
        Bureaucrat tooLow("TooLow", 151);
        (void)tooLow;
    } catch (std::exception& e) {
        std::cerr << "Exception caught (grade 151): " << e.what() << '\n';
    }
}

// 例外系：境界値で increment / decrement を呼んで例外が投げられるか
void testIncrementDecrementErrors()
{
    std::cout << "\n=== Increment/Decrement Error Test (Edges) ===\n";
    try {
        Bureaucrat ceo("CEO", 1);
        std::cout << ceo << '\n';
        std::cout << "Trying to increment CEO...\n";
        ceo.incrementGrade(); // 例外
    } catch (std::exception& e) {
        std::cerr << "Exception caught (increment at 1): " << e.what() << '\n';
    }

    std::cout << "-----------------------------\n";
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << '\n';
        std::cout << "Trying to decrement Intern...\n";
        intern.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Exception caught (decrement at 150): " << e.what() << '\n';
    }
}

int main()
{
    Bureaucrat intern("Intern", 150);
    Bureaucrat junior("Junior", 120);
    Bureaucrat sophomore("Sophomore", 75);
    Bureaucrat senior("Senior", 30);
    Bureaucrat manager("Manager", 10);
    Bureaucrat director("Director", 3);
    Bureaucrat ceo("CEO", 1);

    printBureaucratList(intern, junior, sophomore, senior, manager, director, ceo);
    testNormalIncDec(manager, junior);
    testConstructorExceptions();
    testIncrementDecrementErrors();

    return 0;
}
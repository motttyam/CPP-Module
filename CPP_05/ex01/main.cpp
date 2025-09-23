// ex01/main.cpp
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void divider(const std::string& title) {
    std::cout << "\n===== " << title << " =====\n";
}

int main() {
    // 1) コンストラクタと operator<< の確認
    divider("Constructor & operator<<");
    try {
        Bureaucrat alice("Alice", 30);
        Bureaucrat bob("Bob", 150);
        Form passport("PassportApplication", 30, 20); // 署名30, 実行20
        Form tax("TaxReturn", 75, 75);

        std::cout << alice << std::endl;
        std::cout << bob   << std::endl;
        std::cout << passport << std::endl;
        std::cout << tax      << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    // 2) Form のバリデーション（範囲外等級）
    divider("Form grade validation (exceptions)");
    try {
        Form invalidHigh("InvalidHigh", 0, 10); // 高すぎ -> 例外
        (void)invalidHigh;
    } catch (const std::exception& e) {
        std::cout << "Caught (expected): " << e.what() << std::endl;
    }
    try {
        Form invalidLow("InvalidLow", 151, 10); // 低すぎ -> 例外
        (void)invalidLow;
    } catch (const std::exception& e) {
        std::cout << "Caught (expected): " << e.what() << std::endl;
    }

    // 3) beSigned の成功/失敗
    divider("Form::beSigned (direct) - success & failure");
    {
        Bureaucrat counselor("Counselor", 30);
        Bureaucrat clerk("Clerk", 150);
        Form passport("PassportApplication", 30, 20);
        Form tax("TaxReturn", 75, 75);

        // 成功（30 <= 30）
        try {
            passport.beSigned(counselor);
            std::cout << "Signed OK: " << passport.getFormName()
                      << " by " << counselor.getName() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Unexpected: " << e.what() << std::endl;
        }

        // 失敗（150 > 75）
        try {
            tax.beSigned(clerk);
            std::cout << "Unexpected: clerk signed tax\n";
        } catch (const std::exception& e) {
            std::cout << "Caught (expected): " << e.what() << std::endl;
        }
    }

    // 4) Bureaucrat::signForm のメッセージ（成功/失敗）
    divider("Bureaucrat::signForm messages");
    {
        Bureaucrat counselor("Counselor", 30);
        Bureaucrat clerk("Clerk", 150);
        Form passport("PassportApplication", 30, 20);
        Form tax("TaxReturn", 75, 75);

        // 期待：成功メッセージ（"Counselor signed PassportApplication"）
        counselor.signForm(passport);

        // 期待：失敗メッセージ（"Clerk couldn't sign TaxReturn because ..."）
        clerk.signForm(tax);

        // 期待：再署名の挙動（実装依存だが、ここではもう一度 signForm しても落ちないことを確認）
        counselor.signForm(passport);
    }

    // 5) Bureaucrat の境界操作（ex00 からの流用テイスト）
    divider("Bureaucrat grade bounds");
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        try {
            top.incrementGrade(); // 1 から上げる -> 例外期待
        } catch (const std::exception& e) {
            std::cout << "Caught (expected): " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    divider("Done");
    return 0;
}

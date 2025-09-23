// ex02/main.cpp
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void divider(const std::string& title) {
    std::cout << "\n===== " << title << " =====\n";
}

int main() {

    divider("Setup Bureaucrats & Forms");
    Bureaucrat boss("Boss", 1);          // 何でもできる
    Bureaucrat senior("Senior", 45);     // Robotomy の署名/実行OK
    Bureaucrat signer145("Signer145", 145); // Shrubbery の署名OK
    Bureaucrat staff140("Staff140", 140);   // Shrubbery 実行NG(要137)
    Bureaucrat clerk("Clerk", 150);      // ほぼ何もできない

    ShrubberyCreationForm shrub("home");   // sign 145, exec 137
    RobotomyRequestForm   robo("Bender");  // sign 72,  exec 45
    PresidentialPardonForm pardon("Ford"); // sign 25,  exec 5

    std::cout << shrub << std::endl;
    std::cout << robo  << std::endl;
    std::cout << pardon<< std::endl;

    divider("Sign: success & failure");
    // 署名成功
    signer145.signForm(shrub);   // OK: 145 <= 145
    senior.signForm(robo);       // OK: 45  <= 72
    boss.signForm(pardon);       // OK: 1   <= 25

    // 署名失敗（等級不足）
    clerk.signForm(robo);        // 150 > 72 -> couldn't sign ... because ...

    divider("Execute: error (not signed)");
    // 未署名フォーム実行エラー（別インスタンスで確認）
    ShrubberyCreationForm unsignedShrub("park");
    boss.executeForm(unsignedShrub); // couldn't execute ... because Form is not signed!

    divider("Execute: error (grade too low)");
    // 署名済みだが、実行等級不足
    staff140.executeForm(shrub); // 140 > 137 -> couldn't execute ... because ...

    divider("Execute: success for each concrete form");
    // Shrubbery: ファイル "<target>_shrubbery" に出力
    boss.executeForm(shrub);

    // Robotomy: ドリル音 + 50% 成功/失敗メッセージ
    boss.executeForm(robo);

    // Pardon: 固定メッセージ
    boss.executeForm(pardon);

    divider("Done");
    return 0;
}

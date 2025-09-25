#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    Intern someRandomIntern;

    // テスト対象フォーム名
    std::string validForms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    std::string invalidForm = "invalid form";

    // 正しいフォーム名で生成できるか確認
    for (int i = 0; i < 3; ++i) {
        AForm* form = someRandomIntern.makeForm(validForms[i], "Target_" + std::to_string(i));
        if (form) {
            std::cout << "Success: " << validForms[i] << " created." << std::endl;
            delete form; // メモリリーク防止
        } else {
            std::cout << "Error: " << validForms[i] << " was not created." << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }

    // 無効なフォーム名で NULL が返るか確認
    AForm* badForm = someRandomIntern.makeForm(invalidForm, "Nobody");
    if (!badForm) {
        std::cout << "Correct: invalid form returned NULL." << std::endl;
    } else {
        std::cout << "Error: invalid form should not be created." << std::endl;
        delete badForm;
    }

    return 0;
}
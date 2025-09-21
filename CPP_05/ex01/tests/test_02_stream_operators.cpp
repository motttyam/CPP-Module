#include "helpers.hpp"

int main() {
    divider("operator<< format - Bureaucrat");
    Bureaucrat b("DirectorGeneral", 3);
    {
        CoutCapture cap;
        std::cout << b << std::endl; // 末尾改行も含めて出す
        const std::string out = cap.str();
        // 例: "<name>, bureaucrat grade <grade>.\n"
        const std::string expected = std::string("DirectorGeneral, bureaucrat grade 3.\n");
        if (out != expected) {
            std::cout << "Mismatch!\nExpected: " << expected
                      << "Actual  : " << out;
            return 1;
        }
    }

    divider("operator<< format - Form");
    Form f("TaxReturn", 75, 75);
    {
        CoutCapture cap;
        std::cout << f << std::endl;
        const std::string out = cap.str();
        // あなたのForm出力形式に合わせて調整してください
        // 例: "TaxReturn, is Signed No, grade required to sign75, grade required to execute75.\n"
        const std::string expected = std::string("TaxReturn, is Signed No, grade required to sign75, grade required to execute75.\n");
        if (out != expected) {
            std::cout << "Mismatch!\nExpected: " << expected
                      << "Actual  : " << out;
            return 1;
        }
    }

    std::cout << "All stream operator tests passed.\n";
    return 0;
}

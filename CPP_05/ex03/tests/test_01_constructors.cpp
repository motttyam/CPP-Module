#include "helpers.hpp"
#include <iostream>
#include "../Bureaucrat.hpp"
#include "../ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm.hpp"

static void tryMakeBureaucrat(const std::string& name, int grade){
    try {
        Bureaucrat b(name, grade);
        std::cout << "[created] " << b << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[failed] Bureaucrat(" << name << ", " << grade << ") "
                  << " -> Exception: " << e.what() << std::endl;
    }
}

static void tryMakeShrubbery(const std::string& target){
    try {
        ShrubberyCreationForm f(target);
        std::cout << "[created] " << f << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[failed] ShrubberyCreationForm(" << target << ") "
                  << " -> Exception: " << e.what() << std::endl;
    }
}

static void tryMakeRobotomy(const std::string& target){
    try {
        RobotomyRequestForm f(target);
        std::cout << "[created] " << f << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[failed] RobotomyRequestForm(" << target << ") "
                  << " -> Exception: " << e.what() << std::endl;
    }
}

static void tryMakePardon(const std::string& target){
    try {
        PresidentialPardonForm f(target);
        std::cout << "[created] " << f << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[failed] PresidentialPardonForm(" << target << ") "
                  << " -> Exception: " << e.what() << std::endl;
    }
}

static int failures = 0;

static void expect(bool cond, const char* msg) {
    if (!cond) {
        ++failures;
        std::cerr << "❌ " << msg << std::endl;
    } else {
        std::cerr << "✅ " << msg << std::endl;
    }
}

int main() {
    divider("Bureaucrat Constructor Test");

    // ---- Failure cases ----
    tryMakeBureaucrat("TooLow", 151);  // 例外: GradeTooLowException
    tryMakeBureaucrat("TooHigh", 0);   // 例外: GradeTooHighException

    std::cout << std::endl << "---- Success cases ----" << std::endl;
    tryMakeBureaucrat("Clerk", 150);
    tryMakeBureaucrat("Mid", 75);
    tryMakeBureaucrat("Boss", 1);

    divider("Concrete Form Constructor Test");

    // ---- ShrubberyCreationForm ----
    tryMakeShrubbery("garden");

    // ---- RobotomyRequestForm ----
    tryMakeRobotomy("Bender");

    // ---- PresidentialPardonForm ----
    tryMakePardon("Ford");

    divider("Concrete Form Grades Spec Test");

    ShrubberyCreationForm shrub("garden");   // sign 145, exec 137
    RobotomyRequestForm   robo("Bender");    // sign 72,  exec 45
    PresidentialPardonForm pardon("Ford");   // sign 25,  exec 5

    // ---- Getterで厳密チェック ----
    expect(shrub.getRequiredSignGrade() == 145, "Shrubbery sign grade == 145");
    expect(shrub.getRequiredExecGrade() == 137, "Shrubbery exec grade == 137");

    expect(robo.getRequiredSignGrade() == 72, "Robotomy sign grade == 72");
    expect(robo.getRequiredExecGrade() == 45, "Robotomy exec grade == 45");

    expect(pardon.getRequiredSignGrade() == 25, "Pardon sign grade == 25");
    expect(pardon.getRequiredExecGrade() == 5,  "Pardon exec grade == 5");

    return 0;
}

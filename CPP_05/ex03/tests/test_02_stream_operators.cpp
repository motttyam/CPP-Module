// tests/test_02_stream_operators.cpp
#include "helpers.hpp"
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static int fail(const std::string& title,
                const std::string& expected,
                const std::string& actual) {
    std::cerr << "Mismatch in " << title << "!\n"
              << "Expected: " << expected
              << "Actual  : " << actual;
    return (1);
}

int main() {
    // ===== Bureaucrat =====
    divider("operator<< format - Bureaucrat");
    {
        Bureaucrat b("DirectorGeneral", 3);
        CoutCapture cap;
        std::cout << b << std::endl;
        const std::string out = cap.str();
        const std::string expected = "DirectorGeneral, bureaucrat grade 3.\n";
        if (out != expected) 
            return fail("Bureaucrat", expected, out);
    }

    // ===== AForm（ShrubberyCreationForm）— 未署名 =====
    divider("operator<< format - AForm (Shrubbery, unsigned)");
    {
        ShrubberyCreationForm f("garden"); // sign 145, exec 137
        CoutCapture cap;
        std::cout << f << std::endl;
        const std::string out = cap.str();
        const std::string expected =
            "ShrubberyCreationForm, target: garden, signed: No, "
            "grade required to sign: 145, grade required to execute: 137.\n";
        if (out != expected) 
            return fail("Shrubbery unsigned", expected, out);
    }

    // ===== AForm（ShrubberyCreationForm）— 署名後 =====
    divider("operator<< format - AForm (Shrubbery, signed)");
    {
        ShrubberyCreationForm f("home");
        Bureaucrat boss("Boss", 1);
        f.beSigned(boss);
        CoutCapture cap;
        std::cout << f << std::endl;
        const std::string out = cap.str();
        const std::string expected =
            "ShrubberyCreationForm, target: home, signed: Yes, "
            "grade required to sign: 145, grade required to execute: 137.\n";
        if (out != expected) 
            return fail("Shrubbery signed", expected, out);
    }

    // ===== AForm（RobotomyRequestForm）— 未署名 =====
    divider("operator<< format - AForm (Robotomy, unsigned)");
    {
        RobotomyRequestForm f("Bender"); // sign 72, exec 45
        CoutCapture cap;
        std::cout << f << std::endl;
        const std::string out = cap.str();
        const std::string expected =
            "RobotomyRequestForm, target: Bender, signed: No, "
            "grade required to sign: 72, grade required to execute: 45.\n";
        if (out != expected) 
            return fail("Robotomy unsigned", expected, out);
    }

    // ===== AForm（PresidentialPardonForm）— 未署名 =====
    divider("operator<< format - AForm (Pardon, unsigned)");
    {
        PresidentialPardonForm f("Ford"); // sign 25, exec 5
        CoutCapture cap;
        std::cout << f << std::endl;
        const std::string out = cap.str();
        const std::string expected =
            "PresidentialPardonForm, target: Ford, signed: No, "
            "grade required to sign: 25, grade required to execute: 5.\n";
        if (out != expected) 
            return fail("Pardon unsigned", expected, out);
    }

    std::cout << "All stream operator tests passed.\n";
    return 0;
}

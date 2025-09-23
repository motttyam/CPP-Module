#include "helpers.hpp"
#include <iostream>

static void tryMakeBureaucrat(const std::string& name, int grade){
    try {
        Bureaucrat b(name, grade);
        std::cout << "[created] " << b << std::endl;
    } catch (std::exception& e) {
        std::cerr << "[failed] " << name  << ", bureaucrat grade " << grade <<  "." << std::endl;
        std::cerr << "Exception caught (Bureaucrat constructor): " << e.what() << '\n';
    }
}

static void tryMakeForm(const std::string &formName, int requiredSignGrade, int requiredExecGrade){
    try {
        Form f(formName, requiredSignGrade, requiredExecGrade);
        std::cout << "[created] " << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << "[failed] " << formName  
            << ", grade required to sign " << requiredSignGrade
            << ", grade required to execute " << requiredExecGrade
            <<  "." << std::endl;
        std::cerr << "Exception caught (Form constructor): " << e.what() << '\n';
    }
}

int main() {
    divider("Bureaucrat Constructor Test");
    // ---- Failure cases (should throw) ----
    tryMakeBureaucrat("Unassigned", 151);        //  Too low → GradeTooLowException
    tryMakeBureaucrat("Overqualified", 0);       //  Too high → GradeTooHighException
    std::cout << std::endl;

    // ---- Success cases ----
    tryMakeBureaucrat("Clerk", 150);             //  Lowest valid grade (entry-level clerk)
    tryMakeBureaucrat("AssistantExaminer", 120); //  Junior examiner
    tryMakeBureaucrat("SectionChief", 75);       //  Section chief (mid-level)
    tryMakeBureaucrat("Counselor", 30);          //  Senior counselor
    tryMakeBureaucrat("DeputyDirector", 10);     //  Deputy director
    tryMakeBureaucrat("DirectorGeneral", 3);     //  Director general
    tryMakeBureaucrat("ViceMinister", 1);        //  Vice minister (highest rank)
    std::cout << std::endl;

    divider("Form Constructor Test");
    // ---- Failure cases (should throw) ----
    tryMakeForm("ImperialDecree", 0, 50);            //  Sign grade = 0 → invalid (outside system)
    tryMakeForm("AbolishBureaucracyBill", 100, 151); //  Exec grade = 151 → impossible to execute
    std::cout << std::endl;

    // ---- Success cases ----
    tryMakeForm("ResidencyCertificate", 150, 150);   //  Residency certificate (anyone can process)
    tryMakeForm("SealRegistration", 120, 100);       //  Seal registration (junior official can handle)
    tryMakeForm("TaxReturn", 75, 75);                //  Tax return (mid-level bureaucrat)
    tryMakeForm("PassportApplication", 30, 20);      //  Passport application (senior counselor or above)
    tryMakeForm("BudgetApprovalForm", 10, 5);        //  Budget approval (deputy director level)
    tryMakeForm("BuildingPermit", 1, 1);             //  Building permit (top-level authority)
    std::cout << std::endl;

    return (0);
}

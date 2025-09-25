#include "RobotomyRequestForm.hpp"
#include <cstdlib> 
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this != &other) {
        AForm::operator=(other);
    }
    return (*this);
} 

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::doExecute(const Bureaucrat& b) const {
    (void)b;
    std::cout << "* drilling noises *" << std::endl;

    static bool seed_is_set = false;
    if (!seed_is_set){
        std::srand(std::time(NULL));
        seed_is_set = true;
    }

    if (std::rand() % 2 == 0) {
        std::cout <<  this->getTarget() << " has been robotomized successfully." << std::endl;
    }
    else {
        std::cout << "Robotomy failed on " << this->getTarget() << "." << std::endl;
    }
}
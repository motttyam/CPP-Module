#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    if (this != &other) {
        AForm::operator=(other);
    }
    return (*this);
} 

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::doExecute(const Bureaucrat& b) const {
    (void)b;
    std::cout <<  this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
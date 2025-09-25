#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

AForm* Intern::createShrubbery(const std::string& target){
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target){
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target){
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& name, const std::string& target){
    static const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    static const Intern::Creator creators[] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };

    const size_t N = sizeof(formNames) / sizeof(formNames[0]);

    for (size_t i = 0; i < N; i++) {
        if (name == formNames[i]){
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }
    std::cout 	<< "Intern couldn't create " << name 
				<< " because form name is invali." <<std::endl;
    return (NULL);
}

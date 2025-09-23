#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade()) {
    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::incrementGrade() {
    this->_grade--;
    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(){
    this->_grade++;
    if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &value){
    os << value.getName() << ", bureaucrat grade " << value.getGrade() << ".";
    return (os);
}
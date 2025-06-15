#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(){};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    // コンストラクタ名を話す
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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {}

Bureaucrat::~Bureaucrat(){
	std::cout << "[Bureaucrat]Deconstructor for " << this->getName() << " called" << std::endl;
}

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
    else if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade(){
    this->_grade++;
    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
}

// exceptionのWhatを編集する

std::ostream &operator<<(std::ostream &os, const Bureaucrat &value){
    os << value.getName() << ", bureaucrat grade " << value.getGrade();
    return (os);
}
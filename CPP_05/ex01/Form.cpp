#include "Form.hpp"

Form::Form(const std::string &formName, int requiredSignGrade, int requiredExecGrade)
    : _formName(formName),
      _isSigned(false),
      _requiredSignGrade(requiredSignGrade),
      _requiredExecGrade(requiredExecGrade)
{
    if (this->getRequiredExecGrade() < 1 || this->getRequiredSignGrade() < 1)
        throw Form::GradeTooHighException();
    if (this->getRequiredExecGrade() > 150 || this->getRequiredSignGrade() > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : _formName(other.getFormName()),
      _isSigned(other.getIsSigned()),
      _requiredSignGrade(other.getRequiredSignGrade()),
      _requiredExecGrade(other.getRequiredExecGrade())
{
    if (this->getRequiredExecGrade() < 1 || this->getRequiredSignGrade() < 1)
        throw Form::GradeTooHighException();
    if (this->getRequiredExecGrade() > 150 || this->getRequiredSignGrade() > 150)
        throw Form::GradeTooLowException();
}

Form & Form::operator=(const Form &other) {
    if (this != &other) {
        this->_isSigned = other.getIsSigned();
    }
    return (*this);
}

Form::~Form(){};

std::string const &Form::getFormName() const
{
    return (this->_formName);
};

bool Form::getIsSigned() const
{
    return (this->_isSigned);
}
int Form::getRequiredSignGrade() const
{
    return (this->_requiredSignGrade);
}

int Form::getRequiredExecGrade() const
{
    return (this->_requiredExecGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (this->getRequiredSignGrade() < bureaucrat.getGrade()) {
        throw Form::GradeTooLowException();
    }
    this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &value) {
    os  << value.getFormName() 
        << ", is Signed " << (value.getIsSigned() ? "Yes": "No")
        << ", grade required to sign" << value.getRequiredSignGrade()
        << ", grade required to execute" << value.getRequiredExecGrade()
        << ".";
    return (os);
}
#include "AForm.hpp"

AForm::AForm(const std::string &formName, int requiredSignGrade, int requiredExecGrade, const std::string &target)
    : _formName(formName),
      _isSigned(false),
      _requiredSignGrade(requiredSignGrade),
      _requiredExecGrade(requiredExecGrade),
      _target(target)
{
    if (this->getRequiredExecGrade() < 1 || this->getRequiredSignGrade() < 1)
    	throw AForm::GradeTooHighException();
    if (this->getRequiredExecGrade() > 150 || this->getRequiredSignGrade() > 150)
    	throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _formName(other.getFormName()),
      _isSigned(other.getIsSigned()),
      _requiredSignGrade(other.getRequiredSignGrade()),
      _requiredExecGrade(other.getRequiredExecGrade()),
      _target(other.getTarget())
{
    if (this->getRequiredExecGrade() < 1 || this->getRequiredSignGrade() < 1)
		throw AForm::GradeTooHighException();
    if (this->getRequiredExecGrade() > 150 || this->getRequiredSignGrade() > 150)
        throw AForm::GradeTooLowException();
}

AForm & AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->_isSigned = other.getIsSigned();
    }
    return (*this);
}

AForm::~AForm(){};

std::string const &AForm::getFormName() const {
    return (this->_formName);
};

bool AForm::getIsSigned() const {
    return (this->_isSigned);
}

int AForm::getRequiredSignGrade() const {
    return (this->_requiredSignGrade);
}

int AForm::getRequiredExecGrade() const {
    return (this->_requiredExecGrade);
}

std::string const &AForm::getTarget() const {
    return (this->_target);
};

void AForm::beSigned(const Bureaucrat& b) {
    if (this->getRequiredSignGrade() < b.getGrade()){
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

void AForm::execute(const Bureaucrat& b) const {
    if (!this->getIsSigned()){
        throw AForm::FormNotSignedException();
    }
    if (this->getRequiredExecGrade() < b.getGrade()){
        throw AForm::ExecGradeTooLowException();
    }
    doExecute(b);
}

std::ostream &operator<<(std::ostream &os, const AForm &value) {
    os  << value.getFormName() 
        << ", is Signed " << (value.getIsSigned() ? "Yes": "No")
        << ", grade required to sign" << value.getRequiredSignGrade()
        << ", grade required to execute" << value.getRequiredExecGrade()
        << ".";
    return (os);
}
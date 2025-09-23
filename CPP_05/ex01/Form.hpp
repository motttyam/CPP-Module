#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _formName;
        bool        _isSigned;
        const int         _requiredSignGrade;
        const int         _requiredExecGrade;

    public:
        // Orthodox Canonical Form
        Form();
        Form(const std::string& formName, int requiredSignGrade, int requiredExecGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        
        // getter func
        std::string const &getFormName() const;
        bool getIsSigned() const;
        int  getRequiredSignGrade() const;
        int  getRequiredExecGrade() const;
        
        // member func
        void beSigned(const Bureaucrat& bureaucrat);

        // exception class
        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("Form::GradeTooHighException: Grade is too high (grade < 1)!");
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("Form::GradeTooLowException: Grade is too low (grade > 150)!");
                }
        };
};

// outstream
std::ostream& operator<<(std::ostream &os, const Form &value);

#endif
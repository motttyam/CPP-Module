#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
    private:
        std::string _formName;
        bool        _issigned;
        int         _requiredSignGrade;
        int         _requiredExecGrade;
    public:
        Form();
        Form(const std::string& formName, bool besigned, int requiredSignGrade, int requiredExecGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        void besigned(const Bureaucrat& bureaucrat);

        // // exception class ここをやる
        // class GradeTooHighException : public std::exception {
        //     public:
        //         virtual const char * what() const throw() {
        //             return ("Bureaucrat::GradeTooHighException: Grade is too high (grade < 1)!");
        //         }
        // };
        // class GradeTooLowException : public std::exception {
        //     public:
        //         virtual const char * what() const throw() {
        //             return ("Bureaucrat::GradeTooLowException: Grade is too low (grade > 150)!");
        //         }
        // };
};

std::ostream& operator<<(std::ostream &os, const Form &value);

#endif
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string 	_formName;
        bool        		_isSigned;
        const int         	_requiredSignGrade;
        const int         	_requiredExecGrade;
        const std::string 		_target;
		AForm();

    public:
        // Orthodox Canonical Form
        AForm(const std::string& formName, int requiredSignGrade, int requiredExecGrade, const std::string &target);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        
        // getter func
        std::string const &getFormName() const;
        bool getIsSigned() const;
        int  getRequiredSignGrade() const;
        int  getRequiredExecGrade() const;
		std::string const &getTarget() const;
        
        // member func
        void beSigned(const Bureaucrat& b);
		void execute(const Bureaucrat& b) const; // yaru

		// pure virtual func
		virtual void doExecute(const Bureaucrat& b) const = 0 ;

        // exception class
        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("AForm::GradeTooHighException: Grade is too high (grade < 1)!");
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("AForm::GradeTooLowException: Grade is too low (grade > 150)!");
                }
        };
        class ExecGradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("AForm::ExecGradeTooLowException: Grade is too low to execute form!");
                }
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("AForm::FormNotSignedException: Form is not Signed!");
                }
        };

};

// outstream
std::ostream& operator<<(std::ostream &os, const AForm &value);

#endif
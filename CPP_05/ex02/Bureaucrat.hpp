#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;    
        Bureaucrat();

    public:
        //  Orthodox Canonical Form準拠
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        //　member function
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form) const;  
        void executeForm(const AForm& form) const;

        // exception class
        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("Bureaucrat::GradeTooHighException: Grade is too high (grade < 1)!");
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("Bureaucrat::GradeTooLowException: Grade is too low (grade > 150)!");
                }
        };
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &value);

#endif
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
    private:
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);

    public:
        Intern();
        ~Intern();
        typedef AForm* (*Creator)(const std::string& target);
        static AForm* createShrubbery(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
        static AForm* createPardon(const std::string& target);
        AForm* makeForm(const std::string& name, const std::string& target);
};

#endif
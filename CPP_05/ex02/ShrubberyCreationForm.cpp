#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if (this != &other) {
        AForm::operator=(other);
    }
    return (*this);
} 

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::doExecute(const Bureaucrat& b) const {
    (void)b;
    
    std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
    if (!ofs){
        std::cerr << "Failed to open file" << std::endl;
        return ;
    }
    ofs << "                /\\\n";
    ofs << "               /**\\\n";
    ofs << "              /****\\\n";
    ofs << "             /******\\\n";
    ofs << "            /********\\\n";
    ofs << "           /**********\\\n";
    ofs << "          /************\\\n";
    ofs << "         /**************\\\n";
    ofs << "        /****************\\\n";
    ofs << "       /******************\\\n";
    ofs << "      /********************\\\n";
    ofs << "     /**********************\\\n";
    ofs << "    /************************\\\n";
    ofs << "   /**************************\\\n";
    ofs << "  /****************************\\\n";
    ofs << " /******************************\\\n";
    ofs << "/********************************\\\n";
    ofs << "              ||||||||||\n";
    ofs << "              ||||||||||\n";
    ofs << "              ||||||||||\n";
    ofs << "              ||||||||||\n";
    ofs << "              ||||||||||\n";
    ofs << "              ||||||||||\n";
    ofs << "          ____||||||||____\n";
    ofs << "         /________________\\\n";
}

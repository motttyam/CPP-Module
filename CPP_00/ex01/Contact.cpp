#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(
    const std::string &firstName,
    const std::string &lastName,
    const std::string &nickname,
    const std::string &phoneNumber,
    const std::string &darkestSecret
    ) : _firstName(firstName), 
        _lastName(lastName), 
        _nickname(nickname), 
        _phoneNumber(phoneNumber), 
        _darkestSecret(darkestSecret) {}

std::string Contact::formatField(const std::string field){
    if (field.length() >= CELL_WIDTH)
        return (field.substr(0, CELL_WIDTH -1) + ".");
    return (field);
}

void Contact::displaySummary(int index){
    std::cout << "|" << std::setw(CELL_WIDTH) << std::right << index << "|"
            << std::setw(CELL_WIDTH)  << formatField(this->_firstName) << "|"
			<< std::setw(CELL_WIDTH)  << formatField(this->_lastName) << "|"
			<< std::setw(CELL_WIDTH)  << formatField(this->_nickname) << "|" << std::endl;
}

void Contact::displayDetail(){
    std::cout << "FirstName: " << this->_firstName << std::endl;
    std::cout << "LastName: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
    std::cout << "DarkestSecret: " << this->_darkestSecret << std::endl;
}
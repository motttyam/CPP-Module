#include "Contact.hpp"

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
                 const std::string& phoneNumber, const std::string& darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

std::string Contact::formatField(const std::string field){
    if (field.length() >= CELL_WIDTH)
        return (field.substr(0, CELL_WIDTH -1) + ".");
    return (field);
}

void Contact::displaySummary(int index){
    std::cout << "|" << std::setw(CELL_WIDTH) << std::right << index << "|"
            << std::setw(CELL_WIDTH)  << formatField(this->firstName) << "|"
			<< std::setw(CELL_WIDTH)  << formatField(this->lastName) << "|"
			<< std::setw(CELL_WIDTH)  << formatField(this->nickname) << "|" << std::endl;
}
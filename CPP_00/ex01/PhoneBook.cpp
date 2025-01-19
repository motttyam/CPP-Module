#include "PhoneBook.hpp"


PhoneBook::PhoneBook(){}

void PhoneBook::handleInput(const std::string input){
		if (input == "ADD")
			addNewContact();
		else if (input == "SEARCH")
			searchContact();
		else if (input == "EXIT")
			exit(EXIT_SUCCESS);
		else
			std::cout << "Command is Invalid" << std::endl;
}

void PhoneBook::addNewContact() {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "FirstName: ";
    std::getline(std::cin, firstName);

    std::cout << "LastName: ";
    std::getline(std::cin, lastName);

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);

	std::cout << "Phone Number: ";
	std::getline(std::cin, phoneNumber);

    std::cout << "DarkestSecret: ";
    std::getline(std::cin, darkestSecret);

	Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	if (contacts.size() >= MAX_CONTENTS)
		contacts.pop_front();
	contacts.push_back(newContact);
    return ;
}

void PhoneBook::searchContact(){
	int index;
	// contactが存在しないとき
	if(contacts.size() == 0)
	{
		std::cout << "No Contact" << std::endl;
		return;
	}
	// 項目を出力
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(CELL_WIDTH) << std::right << "Index" 
			<< "|" << std::setw(CELL_WIDTH)  << "First Name"
			<< "|" << std::setw(CELL_WIDTH)  << "Last Name"
			<< "|" << std::setw(CELL_WIDTH)  << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	// contactを出力
	for (size_t i = 0; i < contacts.size(); i++)
		contacts[i].displaySummary(i + 1);
	std::cout << "---------------------------------------------" << std::endl;
	

	std::cout << "Enter the Index of the contact to display" << std::endl;
	std::cin >> index;
	std::cout << index << std::endl;

}
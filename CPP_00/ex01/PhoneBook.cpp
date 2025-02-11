#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

void PhoneBook::handleInput(const std::string input)
{
	if (input == "ADD")
		addNewContact();
	else if (input == "SEARCH")
		searchContact();
	else if (input == "EXIT")
		exit(EXIT_SUCCESS);
	else
		std::cout << "Command is Invalid" << std::endl;
}

void PhoneBook::addNewContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "FirstName: ";
	std::getline(std::cin, firstName);

	std::cout << "LastName: ";
	std::getline(std::cin, lastName);

	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);

	while (true)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, phoneNumber);
		if (validatePhoneNumber(phoneNumber))
			break;
		else
			std::cout << "[CAUTION] Please enter a phone number that is only valid within the country." << std::endl;
	}

	std::cout << "DarkestSecret: ";
	std::getline(std::cin, darkestSecret);

	Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	if (contacts.size() >= MAX_CONTENTS)
		contacts.pop_front();
	contacts.push_back(newContact);
	return;
}

bool PhoneBook::validatePhoneNumber(const std::string &phoneNumber)
{
	bool result = true;

	// 電話番号が数字のみで構成されていることを確認
	if (!std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)){
		std::cout << "ERROR: Please enter a phone number that contains only numeric digits." << std::endl;
		result = false;
	}

	//電話番号の長さを確認
	if (phoneNumber.length() > 15 || phoneNumber.length() < 3){
		std::cout << "ERROR: Phone number should be between 10 and 15 digits long." << std::endl;
		result = false;
	}
	
	return (result);
}

void PhoneBook::searchContact()
{
	int index;
	// contactが存在しないとき
	if (contacts.size() == 0)
	{
		std::cout << "No Contact" << std::endl;
		return;
	}

	// 各項目（タイトル）を出力
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(CELL_WIDTH) << std::right << "Index"
			  << "|" << std::setw(CELL_WIDTH) << "First Name"
			  << "|" << std::setw(CELL_WIDTH) << "Last Name"
			  << "|" << std::setw(CELL_WIDTH) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	// ユーザーがADDで入力した情報を出力
	for (size_t i = 0; i < contacts.size(); i++)
		contacts[i].displaySummary(i + 1);
	std::cout << "---------------------------------------------" << std::endl;

	// ユーザーにIndexを入力させる
	std::cout << "Enter the Index of the contact to display" << std::endl;
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (index < 1 || (size_t)index > contacts.size())
	{
		std::cout << "Invalid Index" << std::endl;
		return;
	}

	// ユーザーが入力したIndexを返す
	contacts[index - 1].displayDetail();
}
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(): _currentIndex(0) {}

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

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

void PhoneBook::addNewContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSeakret;
	
	// 各項目ごとにユーザーがインプットを行う
	validateContent("FirstName: ", &firstName);
	validateContent("LastName: ", &lastName);
	validateContent("Nickname: ", &nickname);
	validatePhoneNumber(&phoneNumber);
	validateContent("DarkestSecret: ", &darkestSeakret);
	
	// 入力された情報をContactクラスとして追加する
	if (_currentIndex == 8){
		for (int i = 0; i < 7; i++) {
			contacts[i] = contacts[i + 1];
		}
		contacts[_currentIndex - 1] = Contact(firstName, lastName, nickname, phoneNumber, darkestSeakret);
	} else if (_currentIndex < 8 && _currentIndex >= 0) {
		contacts[_currentIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSeakret);
		_currentIndex++;
	} else {
		std::cout << "Fatal Error: Index is overflow or underflow" << std::endl;
		exit (1);
	}
}

void PhoneBook::validateContent (const std::string &prompt, std::string *input) {
	
	while ((*input).empty()) {
		std::cout << prompt;
		std::getline(std::cin, *input);
		if(!checkCinInput() || (*input).empty()) {
			std::cout << "Invalid Input: No Input" << std::endl;
		}
	}
}

void PhoneBook::validatePhoneNumber(std::string *phoneNumber){

	while ((*phoneNumber).empty()) {
		std::cout << "PhoneNumber: ";
		std::getline(std::cin, *phoneNumber);
		if(!checkCinInput() || (*phoneNumber).empty()) {
			std::cout << "Invalid Input: No Input" << std::endl;
			continue;
		}

		// 電話番号が数字のみで構成されていることを確認
		for (size_t i = 0; i < (*phoneNumber).length(); i++) {
			if (!isdigit((*phoneNumber).at(i))){
				std::cout << "ERROR: Please enter a phone number that contains only numeric digits." << std::endl;
				(*phoneNumber).clear();
				continue;
			}
		}

		//電話番号の長さを確認
		if (!(*phoneNumber).empty() && ((*phoneNumber).length() > 15 || (*phoneNumber).length() < 3)){
			std::cout << "ERROR: Phone number should be between 10 and 15 digits long." << std::endl;
			(*phoneNumber).clear();
			continue;
		}
	}
}

bool PhoneBook::checkCinInput (){
	if (std::cin.eof()){
		std::cout << "Imput EOF: Terminating this program..." << std::endl;
		std::cin.clear();
		exit(EXIT_SUCCESS);
		}

	// i/oに甚大なエラーが発生したとき
	else if (std::cin.fail() || std::cin.bad()){
		std::cout << "ERROR: A Input error has occurred." << std::endl;
		exit(EXIT_FAILURE);
	}

	return (true);
}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

void PhoneBook::searchContact()
{
	int index;
	// contactが存在しないとき	
	if (_currentIndex == 0)
	{
		std::cout << "No Contact" << std::endl;
		return;
	}

	// contactが存在するとき
	std::cout << "|" << std::setw(CELL_WIDTH) << "Index" << "|"
		<< std::setw(CELL_WIDTH) << "FirstName" << "|"
		<< std::setw(CELL_WIDTH) << "LastName" << "|"
		<< std::setw(CELL_WIDTH) << "NickName" << "|"
		<< std::endl;
	for (int i = 0; i < _currentIndex; i++) {
		contacts[i].displaySummary((int)i + 1);
	}
	std::cout << "---------------------------------------------" << std::endl;

	// ユーザーにIndexを入力させる
	std::cout << "Enter the Index of the contact to display" << std::endl;
	index = PhoneBook::validateIndex();

	if (index < 1 || index > _currentIndex)
	{
		std::cout << "Invalid Index" << std::endl;
		return;
	}

	// ユーザーが入力したIndexを返す
	contacts[index - 1].displayDetail();
}

int  PhoneBook::validateIndex () {
	
	std::string input;

	while (input.empty()) {
		// ユーザーが文字列を入力する
		std::getline(std::cin, input);

		// 標準入力が正しいか確認する
		if(!checkCinInput() || input.empty()) {
			std::cout << "Invalid Input: No Input" << std::endl;
			continue;
		}
		
		// 文字列に含まれるcharがすべて数字であるかを確認する
		for (size_t i = 0; i < input.size(); i++){
			if (isdigit(input.at(i)) == false) {
				input.clear();
				std::cout << "Invalid Input: Input should be only digit" << std::endl;
				continue;
			}
		}
	}
	return (atoi(input.c_str()));
}
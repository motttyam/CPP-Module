#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <algorithm>
# include <cctype>
# include <cstdlib>
# include <deque>
# include <iostream>
# include <iostream>
# include <limits>
# include <string>

# define MAX_CONTENTS 8

class PhoneBook
{
  public:
	PhoneBook();
	void handleInput(const std::string input);
	void addNewContact();
    bool checkCinInput();
    void searchContact();
    bool validatePhoneNumber(const std::string &phoneNumber);

  private:
	std::deque<Contact> contacts;
};

#endif
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <deque>
# include <iostream>
# define MAX_CONTENTS 8

class PhoneBook
{
  public:
	PhoneBook();
	void handleInput(const std::string input);
	void addNewContact();
    void searchContact();

private:
	std::deque<Contact> contacts;
};

#endif
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

# define MAX_CONTACTS 8

class PhoneBook
{
  private:
	  Contact contacts[8];
    int _currentIndex;

  public:
    PhoneBook();
    void handleInput(const std::string input);
    void addNewContact();
    void validateContent(const std::string &prompt, std::string *input);
    bool checkCinInput();
    void searchContact();
    int validateIndex();
    void validatePhoneNumber(std::string *phoneNumber);
};

#endif
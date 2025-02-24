#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <string>
# define CELL_WIDTH 10

class Contact
{
  public:
	Contact();
	Contact(
        const std::string &firstName,
        const std::string &lastName,
		const std::string &nickname,
        const std::string &phoneNumber,
		const std::string &darkestSecret
    );
    std::string formatField(const std::string field);
    void displaySummary(int index);
	void displayDetail();

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
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

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
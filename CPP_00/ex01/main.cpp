#include "phonebook.h"

int main(void)
{
	std::string input;
	PhoneBook phonebook;

	while (1)
	{
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			Contact contact;
			contact.fill_contact();
			phonebook.add(contact);
		}
		else if (input == "SEARCH")
		{
			phonebook.list();
			phonebook.entry();
		}
	}
	return (0);
}

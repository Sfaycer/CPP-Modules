#include "phonebook.h"

Contact::Contact(void)
{
	this->first_name = &this->inputs[0];
	this->inputs_str[0] = "First Name";
	this->last_name = &this->inputs[1];
	this->inputs_str[1] = "Last Name";
	this->nickname = &this->inputs[2];
	this->inputs_str[2] = "Nickname";
	this->phone_number = &this->inputs[3];
	this->inputs_str[3] = "Phone Number";
	this->darkest_secter = &this->inputs[4];
	this->inputs_str[4] = "Darkest Secret";
}

void Contact::fill_contact(void)
{
	int i = 0;

	while (i < 5)
	{
		std::cout << "Enter " << this->inputs_str[i] << ": ";
		std::getline(std::cin, this->inputs[i]);
		i++;
	}
}

std::string Contact::getInfofield(int j) const
{
	return (this->inputs[j]);
}

void Contact::printContactInfo(void) const
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << this->inputs_str[i] << ": ";
		std::cout << this->inputs[i] << std::endl;
	}
}

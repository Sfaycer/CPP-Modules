#include "phonebook.h"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->filled = 0;
}

void PhoneBook::add(Contact contact)
{
	this->contacts[this->index] = contact;
	this->index = (this->index + 1) % 8;
	if (this->filled < 8)
		this->filled++;
}

void PhoneBook::list(void)
{
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;

	for (int i = 0; i < this->filled; i++)
	{
		std::cout << std::setw(10) << std::setiosflags(std::ios::right);
		std::cout << i + 1;
		for (int j = 0; j < 3; j++)
		{
			std::cout << "|";
			std::cout << std::setw(10) << std::setiosflags(std::ios::right);
			std::string temp = this->contacts[i].getInfofield(j);
			if (temp.size() > 10)
			{
				temp.resize(9);
				temp += '.';
			}
			std::cout << temp;
		}
		std::cout << std::endl;
	}
}

bool PhoneBook::atoi(const char *str, int *num)
{
	int	cutoff;

	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	cutoff = 214748364;
	*num = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (*num > cutoff || (*num == cutoff && (*str - '0') > 7))
			return (false);
		*num = *num * 10 + (*str - '0');
		str++;
	}
	if (*str)
		return (false);
	return (true);
}

void PhoneBook::entry(void)
{
	std::string input;
	int num;

	std::cout << "Enter Index of the desired entry: ";
	std::getline(std::cin, input);
	if (!this->atoi(input.c_str(), &num))
		std::cout << "Invalid Index" << std::endl;
	else
	{
		if (num > 0 && num <= this->filled)
			this->contacts[num - 1].printContactInfo();
		else
			std::cout << "Invalid Index" << std::endl;
	}
}

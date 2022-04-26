#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <string>
# include "Contact.class.hpp"

class PhoneBook
{
	private:
		int index;
		int filled;
		Contact contacts[8];
		bool atoi(const char *str, int *num);
	public:
		PhoneBook(void);
		void add(Contact contact);
		void list(void);
		void entry(void);
};

#endif

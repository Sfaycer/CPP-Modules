#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact
{
	private:
		std::string *first_name;
		std::string *last_name;
		std::string *nickname;
		std::string *phone_number;
		std::string *darkest_secter;
		std::string inputs[5];
		std::string inputs_str[5];
	public: 
		Contact(void);
		void fill_contact(void);
		void list(void);
		std::string getInfofield(int j) const;
		void printContactInfo(void) const;
};

#endif

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private :
		Contact contacts[8];
		int	contactcount;
		int currentindex;
		std::string formatfield(std::string text);
	public :
		PhoneBook();
		~PhoneBook();
		int getcontactcount();
		void addcontact(Contact _newcontact);
		void searchcontact();
		void displaydetails(int _index);
		bool isnumber(const std::string str);
		int ft_atoi(const std::string str);
};
#endif

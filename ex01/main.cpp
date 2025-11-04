#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>
int main()
{
	PhoneBook phonebook;
	
	std::string line;
	while(1)
	{
		std::getline(std::cin, line);
		if(line == "ADD" || line == "SEARCH" || line == "EXIT")
		{
			if(line == "ADD")
			{
				Contact newcontact;
				std::getline(std::cin,line).
				newcontact.setfirstname(line);
				std::getline(std::cin,line).
				newcontact.setlastname(line);
				std::getline(std::cin,line).
				newcontact.setnickname(line);
				std::getline(std::cin,line).
				newcontact.setphonenumber(line);
				std::getline(std::cin,line).
				newcontact.setdarkestsecret(line);
				phonebook.addcontact(newcontact);
			}
			else if(line == "SEARCH")
			else
				return(0);
		}

	}
}
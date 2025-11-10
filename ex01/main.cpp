#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>
#include <string>
int main()
{
	PhoneBook phonebook;
	int index;
	std::string line;
	while(1)
	{
		std::cout<<"what do you want to do?"<<std::endl;
		std::getline(std::cin, line);
		if(line == "ADD" || line == "SEARCH" || line == "EXIT")
		{
			if(line == "ADD")
			{
				Contact newcontact;
				std::cout <<"firstname: ";
				std::getline(std::cin,line);
				newcontact.setfirstname(line);
				line = "\0";
				std::cout <<"lastname: ";
				std::getline(std::cin,line);
				newcontact.setlastname(line);
				line = "\0";
				std::cout <<"nickname: ";
				std::getline(std::cin,line);
				newcontact.setnickname(line);
				line = "\0";
				std::cout <<"phonenumber: ";
				std::getline(std::cin,line);
				newcontact.setphonenumber(line);
				line = "\0";
				std::cout <<"darkestsecret: ";
				std::getline(std::cin,line);
				newcontact.setdarkestsecret(line);
				line = "\0";
				phonebook.addcontact(newcontact);
			}
			else if(line == "SEARCH")
			{
				line = "\0";
				phonebook.searchcontact();
				std::cout << "Enter the index of the contact you want to display: ";
				while (true)
				{
    				std::getline(std::cin, line);
    				if (!phonebook.isnumber(line))
    				{
        				std::cout << "Invalid input." << std::endl;
        				std::cout << "Enter the index of the contact you want to display: ";
        				continue;
    				}
    				index = phonebook.ft_atoi(line);
    				if (index >= phonebook.getcontactcount() || index < 0)
    				{
        				std::cout << "Invalid index." << std::endl;
        				std::cout << "Enter the index of the contact you want to display: ";
        				continue;
    				}
    				break;
				}
				phonebook.displaydetails(index);
			}
			else
				return(0);
		}
		else
			std::cout<<"invalid command"<<std::endl;
	}
}
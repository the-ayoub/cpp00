#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    contactcount = 0;
	currentindex = 0;
}
void	PhoneBook::addcontact(Contact _newcontact)
{
	contacts[currentindex] = _newcontact;
	currentindex++;
	if(currentindex == 8)
		currentindex = 0;
	if(contactcount < 8)
		contactcount++;
}
std::string PhoneBook::formatfield(std::string text)
{
	int length = text.length();
	if(length > 10)
		text = text.substr(0,9) + ".";
	return(text);
}
void PhoneBook::searchcontact()
{
	std::cout<<"     index|first name| last name|  nickname|";
	for (int i=0; i<contactcount; i++)
	{
		std::cout << std::setw (10) << std::right << i << "|";
		std::cout << std::setw (10) << std::right << formatfield(contacts[i].getfirstname()) <<  "|";
		std::cout << std::setw (10) << std::right << formatfield(contacts[i].getlastname()) << "|";
		std::cout << std::setw (10) << std::right << formatfield(contacts[i].getnickname()) << "|" << std::endl;
	}
}

void displaydetails(int index)
{
	std::cout<< "firstname: " <<contacts[index].getfirstname() << std::endl;
	std::cout<< "lastname: " <<contacts[index].getlastname() << std::endl;
	std::cout<< "nickname: " <<contacts[index].getnickname() << std::endl;
	std::cout<< "phonenumber: " <<contacts[index].getphonenumber() << std::endl;
	std::cout<< "darkestsecret: " <<contacts[index].getdarkestsecret() << std::endl;
}

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}
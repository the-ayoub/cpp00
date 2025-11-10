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
	std::cout<<"     index|first name| last name|  nickname|"<<std::endl;
	for (int i=0; i<contactcount; i++)
	{
		std::cout << std::setw (10) << std::right << i << "|";
		std::cout << std::setw (10) << std::right << formatfield(contacts[i].getfirstname()) <<  "|";
		std::cout << std::setw (10) << std::right << formatfield(contacts[i].getlastname()) << "|";
		std::cout << std::setw (10) << std::right << formatfield(contacts[i].getnickname()) << "|" << std::endl;
	}
}

void PhoneBook::displaydetails(int _index)
{
	std::cout<< "firstname: " <<contacts[_index].getfirstname() << std::endl;
	std::cout<< "lastname: " <<contacts[_index].getlastname() << std::endl;
	std::cout<< "nickname: " <<contacts[_index].getnickname() << std::endl;
	std::cout<< "phonenumber: " <<contacts[_index].getphonenumber() << std::endl;
	std::cout<< "darkestsecret: " <<contacts[_index].getdarkestsecret() << std::endl;
}
bool PhoneBook::isnumber(const std::string str)
{
	if(str == "\0")
		return(false);
	else
	{
		for(size_t i=0; i<str.length();i++)
		{
			if(!isdigit(str[i]))
				return(false);
		}
		return(true);
	}
}
int PhoneBook::getcontactcount()
{
	return(contactcount);
}
int PhoneBook::ft_atoi(const std::string str)
{
    int sign = 1;
    int result = 0;
    size_t i = 0;

    if (i < str.length() && (str[i] == '-' || str[i] == '+'))
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (i < str.length() && std::isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
PhoneBook::~PhoneBook() {}
#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>


bool isnumber(const std::string str)
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
int ft_atoi(const std::string str)
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
				while(true)
				{
					Contact newcontact;
					while(true)
					{
						std::cout <<"firstname: ";
						std::getline(std::cin,line);
						if(line != "\0")
						{
							newcontact.setfirstname(line);
							break;
						}
					}
					while(true)
					{
						std::cout <<"lastname: ";
						std::getline(std::cin,line);
						if(line != "\0")
						{
							newcontact.setlastname(line);
							break;
						}
					}
					while(true)
					{	
						std::cout <<"nickname: ";
						std::getline(std::cin,line);
						if(line != "\0")
						{
							newcontact.setnickname(line);
							break;					
						}
					}
					while(true)
					{
						std::cout <<"phonenumber: ";
						std::getline(std::cin,line);
						if(line != "\0")
						{
							newcontact.setphonenumber(line);
							break;
						}
					}
					while(true)
					{
						std::cout <<"darkestsecret: ";
						std::getline(std::cin,line);
						if(line != "\0")
						{
							newcontact.setdarkestsecret(line);
							break;
						}
					}
					phonebook.addcontact(newcontact);
					break;
				}
			}
			else if(line == "SEARCH")
			{
				phonebook.searchcontact();
				std::cout << "Enter the index of the contact you want to display: ";
				while (true)
				{
    				std::getline(std::cin, line);
    				if (!isnumber(line))
    				{
        				std::cout << "Invalid input." << std::endl;
        				std::cout << "Enter the index of the contact you want to display: ";
        				continue;
    				}
    				index = ft_atoi(line);
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

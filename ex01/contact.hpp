#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private :
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkestsecret;
	public :
		Contact();
		~Contact();
		void setfirstname(std::string _firstname);
		void setlastname(std::string _lastname);
		void setnickname(std::string _nickname);
		void setphonenumber(std::string _phonenumbre);
		void setdarkestsecret(std::string _darkestsecret);
		std::string getfirstname();
		std::string getlastname();
		std::string getnickname();
		std::string getphonenumber();
		std::string getdarkestsecret();
};

#endif
#include "contact.hpp"

void Contact::setfirstname(std::string _firstname)
{
	firstname = _firstname;
}
void Contact::setlastname(std::string _lastname)
{
	lastname = _lastname;
}
void Contact::setnickname(std::string _nickname)
{
	nickname = _nickname;
}
void Contact::setphonenumber(std::string _phonenumbre)
{
	phonenumber = _phonenumbre;
}
void Contact::setdarkestsecret(std::string _darkestsecret)
{
	darkestsecret = _darkestsecret;
}
std::string Contact::getfirstname()
{
	return(firstname);
}
std::string Contact::getlastname()
{
	return(lastname);
}
std::string Contact::getnickname()
{
	return(nickname);
}
std::string Contact::getphonenumber()
{
	return(phonenumber);
}
std::string Contact::getdarkestsecret()
{
	return(darkestsecret);
}

Contact::Contact() {}

Contact::~Contact() {}
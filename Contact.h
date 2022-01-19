/** @file Contact.h */
#ifndef CONTACT_H_
#define CONTACT_H_
#include <string>

using namespace std;

/** The Contact class will create an object of Contacts, storing their first name,
last name and birthdate together. This class will be able to modify the Contacts and retreive specific
parts of the Contacts using the given functions*/

class Contact 
{

private:

//private data member to store the first name
string firstName;
//private data member to store last name
string lastName;
//private data member to store the birthdate
string birthDate;

public:

//Will Return First Name
string getFirstName() const;

//Will Return the Last Name
string getLastName()const;

//Will Return the Birthdate
string getBirthdate()const;

//Updates the firstName
void setfirstName(string FirstName);
//Updates the lastName
void  setlastName(string LastName);

//Updates the birthdate
void setbirthdate(string month, string day, string year);

//friend overload operator, to sort contacts according to their last name
friend bool operator < ( const Contact& lhs , const Contact& rhs );

//friend overload operator, to sort contacts according to their last name    
friend bool operator > ( const Contact& lhs , const Contact& rhs );
    
};

#endif



/** @file Contact.cpp */

#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;


//Will Return First Name
string Contact::getFirstName()const{
    return firstName;

}

//Will Return the Last Name
string Contact::getLastName()const
{
    return lastName;

}

//Will Return the Birthdate
string Contact::getBirthdate()const
{
    return birthDate;
}

//Updates the firstName
void Contact::setfirstName(string FirstName)
{
     firstName = FirstName;
}
//Updates the lastName
void Contact::setlastName(string LastName)
{
    lastName = LastName;
}

//Updates the birthdate
void Contact::setbirthdate(string month, string day, string year)
{
   birthDate  = month + "/" + day + "/" + year;
}

//Overload operator to sort contacts by last name
bool operator < ( const Contact& lhs , const Contact& rhs )
       {
          if(lhs.getLastName() == rhs.getLastName()){
             
             return lhs.getFirstName()  < rhs.getFirstName();
          }
          return lhs.getLastName() < rhs.getLastName(); 
             
       }

//Overload operator to sort contacts by last name     
bool operator > ( const Contact& lhs , const Contact& rhs ){
        if(lhs.getLastName() == rhs.getLastName()){
            
             return lhs.getFirstName()  > rhs.getFirstName();
          }
      return lhs.getLastName() > rhs.getLastName(); 
       }





 


#include "Contact.h"
#include "ContactList.h"
#include "string_tools.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

/** Drivercode myContacts will incorporate the Contacts Class and Contactlist Class and read in 2 files, 
Contacts and Commands to modify the Contact List based on the Commands file, will output final 
modified contact list as the commands occur, until it reaches the end of the file.*/

int main() {
   
/** Declaring two ifstreams for contacts and commands file */
ifstream file1, file2; 
/** Declaring string variables to store file names, Contact Class components from file */
string contactFileName, commandsFileName, line, first, last, month, day, year;     
/** Declaring char variable to store how the string will be split from file */
char delimiter = ',';  
/** Declaring two vectors to store string values from the split function */
vector<string> lineSplit, temp;  
/** Declaring ContactList Object ModifiedContacts */
ContactList modifiedContacts;

/** Read the contact file and commands file name */
cin>> contactFileName >> commandsFileName;

/** Read the contact file provided and add in the contact details */
file1.open(contactFileName);                                         /** opening file */
if (file1.is_open())                                  
    {   
      while(getline(file1, line))                                    /** reading each line of file */        
      { 
        Contact entry;                                               /** creating an Contact Class object entry to add in intial contact list */ 
        lineSplit = split(line, delimiter);                          /** removing commas from the string line read in */ 
        for(unsigned i = 0; i<lineSplit.size(); i++)                 /** cleans the string values */ 
      {
          lineSplit.at(i) = removeSpecials(lineSplit.at(i));         
      }
          first = lineSplit.at(0);                                   /** extracting first name */ 
          entry.setfirstName(first);                                 /** storing first name in contact object entry */ 
          last = lineSplit.at(1);                                    /** extracting last name */
          entry.setlastName(last);                                   /** storing last name in contact object entry */
          month = lineSplit.at(2);                                   /** extracting birth_month name */
          day = lineSplit.at(3);                                     /** extracting birth_day name */
          year = lineSplit.at(4);                                    /** extracting birth_year name */
          entry.setbirthdate(month,day, year);                       /** storing birthdate in contact object entry */
         
          modifiedContacts.add(entry);                               /** adding the intial contact list into the ContactList Class */
         
          lineSplit.clear();                                          /** clearing the split vector for next line */
      }
    }

/** if file doesn't open */
// else{
// cout<< "File failed to open"<< endl;
//     }                                       
     
/** Outputing the size of the initial contact list provided */
cout<< "Loaded " << modifiedContacts.getSize() <<" records into contact list."<<endl;



file2.open(commandsFileName);                                       /** opening file */
if (file2.is_open())                                                 
    {   
      while(getline(file2, line))                                   /** reading each line in file */
      { 
   
        lineSplit = split(line, delimiter);                         /** using split function to remove commas */
        for(unsigned i = 0; i<lineSplit.size(); i++)
      {
          lineSplit.at(i) = removeSpecials(lineSplit.at(i));         /** cleans up string values */    
      }
      
      string letter = lineSplit.at(0);                               /** storing the letter of the command in variable */
      char command = letter[0];                                      /** extracting the command character and storing into a variable */
      Contact entry1;                                                /** creating a Contact object entry1 to store any new contact info */
      
      /** Switch commands according to the commands file */
      switch(command) 
      {                            
      case 'A' :                                                     /** Will ADD in a new Contact */
          letter.erase(0,2);                                         /** removing the command letter and space */
          entry1.setfirstName(letter);                               /** storing first name in contact object entry1 */
          last = lineSplit.at(1);                                    /** extracting last name  */
          entry1.setlastName(last);                                  /** storing last name in contact object entry1 */
          month = lineSplit.at(2);                                   /** extracting month */
          day = lineSplit.at(3);                                     /** extracting day */
          year = lineSplit.at(4);                                    /** extracting year*/
          entry1.setbirthdate(month,day, year);                      /** storing birthdate in contact object entry1 */
          
          modifiedContacts.add(entry1);                              /** Adding new contact to ContactList ModifiedContacts */
          
           cout<< "New contact added"<<endl;                         /** outputting new contact added */
           cout<<"  "<<  entry1.getFirstName() << " " <<
                    entry1.getLastName() << ", " << 
                    entry1.getBirthdate()<<endl;
         break;
      case 'D' : 
      {                                                     /** Will DELETE a unique contact only in list based on last name */
         letter.erase(0,2);
         if(lineSplit.size() == 1)
         {
         modifiedContacts.remove(letter); 
         }
         else
         {
          string key = letter + " " + lineSplit.at(1);
          modifiedContacts.remove(key);
         }
       }
         break;
      case 'F' :                                                      /** Will FIND contact with last name provided */
         letter.erase(0,2);
         modifiedContacts.contains(letter); 
         break;
      case 'R' :                                                      /** Will REMOVE ALL contacts with given last name */
         letter.erase(0,2);
         modifiedContacts.removeAll(letter); 
         break;
      case 'S' :                                                       /** Will SHOW Contact List as its modified in order of lastname */
       modifiedContacts.showList(); 
       break;
      default :
         cout << "Invalid" << endl;
     }
    }
    }
 
 /** if file doesn't open */   
 /*else{
      cout<< "File failed to open"<< endl;
     }   */
    
/** Will send the contents of the (unordered) contact list to 
 standard output after reporting how many records are in the database */
 
 cout<< "Wrote "<< modifiedContacts.getSize() << " records from contact list."<<endl;

 modifiedContacts.finalContactList();
 
 
 
   
   return 0;
}

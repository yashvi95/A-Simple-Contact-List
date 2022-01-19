/** @file ContactList.h */
#ifndef CONTACTLIST_
#define CONTACTLIST_
#include "Database.h"
#include "Contact.h"
#include <string>
#include "NotFoundException.h"
#include <set>
#include <vector>
#include<map>
#include<string>

using namespace std;

/** The class ContactList is inherited from the template class Database which will store Contacts 
in an unordered vector and an ordered multimap. Will add in contacts using the class Contact, 
will modify the contactlist using the commands provided by the user. Will be able to Add, Delete, Remove,
Determine size of the ContactList, Determine if Contact list is empty, Get a specific Entry, and will 
be able to Find a specific contact all based on the key provided, the last name and will modify 
the list accordingly. Will be able to display the Contacts as they are being modified and will
send the contents of the (unordered) vector database to standard output */

class ContactList: public Database < Contact, string >
{

private: 
   //private data member to store unordered Contacts into a vector
   vector<Contact> database;
   //private data member to store the indexing of the Contact in a map in order
   multimap<string, unsigned> index;


public:
     
    /** Tests whether this database is empty.
        @return True if the database is empty, or false if not. */
     bool isEmpty() const;

    /** Determines the number of entries (records) in the database.
        @return The number of entries/records in the database. */
     unsigned getSize() const;

    /** Adds a new record into the database.
        @param newData  The new record to add to the database.
        @post  The database contains the new record.
        @return  True if the addition is successful, or false if not. */
     bool add(const Contact& newData);

    /** Removes the record with the given key from this database.
	    Returns false if duplicate records matching the key exist.
		Default format for aKey is the value of the key (based on index);
        otherwise, two values may be provided, separated by commas,
        to identify a particular record that matches the extended key
        (done if there are duplicates).
        @param aKey  The key of the record to remove from the database.
        @return  True if the removal is successful, or false if not. */
     bool remove(const string& aKey);

    /** Removes all record(s) with the given key from this database.
        @param aKey  The key of the record(s) to remove from the database.
        @return  True if the removal is successful, or false if not. */
     bool removeAll(const string& aKey);

    /** Removes all records from this database. */
     void clear() ;

    /** Gets an entry (or entries) with the matching key from this database.
        @post  The desired entry/entries has been returned in a set, and the
            database is unchanged. If no such entry was found, an exception
            is thrown.
        @param aKey  The key of the record to locate from the database.
        @return  The set containing the entry (or entries) in the database
            that matches the given search key.
        @throw  NotFoundException if the given entry is not in the database. */
     set<Contact> getEntry( const string& aKey ) const throw(NotFoundException);

    /** Tests if an entry matching the given key occurs in this database.
        @post  The database is unchanged.
        @param aKey  The search key of the entry to find.
        @return  True if the entry occurs in the database, or false if not. */
     bool contains( const string& aKey ) const;
     
     /** Displays ContactList based on the updated commands */
     void showList();
     
     /** Displays the FINAL unordered Database to standard output */ 
     void finalContactList();
     
    /** Destroys object and frees memory allocated by object. */
     ~ContactList() {  }

}; // end Database
#endif
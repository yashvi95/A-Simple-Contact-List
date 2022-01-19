/** @file ContactList.cpp */
#include "ContactList.h"
#include "string_tools.h"
#include <iostream>
#include <iterator>

using namespace std;

//Will Check is DataBase is empty
bool ContactList::isEmpty() const
     {
         if(database.size() == 0)
         {
             return true;
         }
         return false;
     }

//Will return Database size
unsigned ContactList::getSize() const
     {
         return database.size();
     }

//Will return true is new contact is added to database, and according to the pos, to the index_map  
bool ContactList::add(const Contact& newData) 
     {
        
         database.push_back(newData);
         unsigned position = database.size()-1;
         index.insert(make_pair(database.at(position).getLastName(),position));

        
         return true;
     }

//Will remove unique contact matching the aKey = last name and will update database and index accordingly
bool ContactList::remove( const string& aKey )
     {   
        vector<string> name;
        name = split(aKey, ' ');
        
   
       if(name.size() == 1)
       {
          cout<< "Delete "<<'"'<< aKey << '"'<<endl;
          
          //Will determine all contacts with the same last name
          auto key = index.equal_range(aKey);
          
         
          //Will count the number of contacts matched with the same last name
          unsigned count = 0;
          for (auto it = key.first; it!=key.second; ++it)
          {
              count++;
          }
          
         //If there is a matching contact, then will continue
         if(index.find(aKey) != index.end())
         {
          for (auto it = key.first; it!=key.second; ++it)
          {
             //If there is a unique contact will remove
              if(count == 1)          
              {
   
                   cout<<"  "<<  database.at(it->second).getFirstName() << " " <<
                   database.at(it->second).getLastName() << ", " 
                   << database.at(it->second).getBirthdate()<<endl;
               
                   //Storing the last Contact in database into a string
                   string repl = database.at(database.size() - 1).getLastName();  
                   //Will find the last contact in database and will store in iterator to the index_map
                   auto replace = index.find(repl);
                   //Will replace the position of the last contact with the position of the contact to be deleted
                   replace->second = it->second; 
                   //Will replace the contact position that is being removed with the last pos contact
                   database.at(it->second) = database.at(database.size() - 1);
                   //Delete the last contact in database
                   database.pop_back();
                   //Will delete the unique contact from index_map
                   index.erase(aKey);
         
                  
                   cout<< "  Done." <<endl;
                   
                   return true;
                           
                    
              }
              else
              {     
                    //Else if multiple contacts with same last name occur, then will output contacts
                    //But will not delete the contacts.
                    cout<< "  Multiple matches for " << '"' << aKey << '"'<< endl;
               //To print in alphabetical order, have to insert into a set and then outpute contacts
                    set<Contact> sameLast;
                  for (auto it = key.first; it!=key.second; ++it)
                    {
                      sameLast.insert(database.at(it->second));
                    }
      
               for(const auto& a : sameLast)
                   {
                       cout<<"  ";
                       cout<< a.getFirstName() << " " <<
                        a.getLastName() << ", "<<
                        a.getBirthdate()<<endl;   
                    }
                    
                    cout << "  Not done."<<endl;
                    return false;      
              }
            }
          }  
        
        else{
              cout<<"  Not found."<<endl;
              return false;
              }
              
        }
        
     else 
        {
           //The case where the first and last name are entered to be removed
           //Need to seperate the first and last name, search for the unique entry
            cout<< "Delete "<< '"'<< name.at(0)<< "," << name.at(1) << '"'<< endl;
            
            auto key = index.equal_range(name.at(0));            //find all the key elements with same last name
            unsigned num;                                        //local variable to store the unique index to be deleted 
            for(unsigned i = 0; i<database.size(); i++)
            {
               if(database.at(i).getFirstName() == name.at(1))
               {
                     num = i;     //store the index value to find in the index_map from the database
               }         
            }
               cout<<"  "<<  database.at(num).getFirstName() << " " <<
                             database.at(num).getLastName() << ", " 
                            << database.at(num).getBirthdate()<<endl;    
              
              //Finds the unique key element to be deleted from the index_map and updates the last element of the databse with the index of the one to be deleted.
               for (auto it = key.first; it!=key.second; ++it)
               {
                  if(it->second == num)
                  {
                             
                  for(auto i = index.begin(); i!=index.end(); i++)
                  {
                     if(i->second == database.size() - 1)
                     {
                        i->second =  it->second;
                        index.erase(i);
                     }
                  }
                   
                   //Will replace the contact position that is being removed with the last pos contact
                   database.at(it->second) = database.at(database.size() - 1);
                   //Delete the last contact in database
                   database.pop_back();
                   //Will delete the unique contact from index_map
                   
                     }
                 }
                  
                 
                cout<< "  Done." <<endl;
                   
                return true;
                   

        }
        
     
              
      }

//Will remove all the contacts wil the given last name    
bool ContactList::removeAll( const string& aKey )
     {
        cout<< "Remove "<<'"'<< aKey << '"'<<endl;
       //Will find all the contacts with given last name 
        auto key = index.equal_range(aKey);
      //Will count the number of matching contacts found    
      unsigned count = 0;
      for (auto it = key.first; it!=key.second; ++it)
          {
              count++; 
          } 
             
      //If the contact is in the database    
      if(index.find(aKey) != index.end())
         {
          //Will iterate through the matching contacts and remove all of them while outputting them
          for (auto it = key.first; it!=key.second; ++it)
          {
            for (auto it = key.first; it!=key.second; ++it)
          {
                   cout<<"  "<< database.at(it->second).getFirstName() << " " <<
                   database.at(it->second).getLastName() << ", " << 
                   database.at(it->second).getBirthdate()<<endl;
          }
         //Will update the database and index_map according to the number of contacts to be removed
         for(unsigned i = 0; i<count; i++)
            {
            
                   string repl = database.at(database.size() - 1).getLastName();            
                   auto replace = index.find(repl);
                   replace->second = it->second;
                   database.at(it->second) = database.at(database.size() - 1);
                   database.pop_back();
                   index.erase(aKey);
   
             }
                   cout<< "  Done." <<endl;
                   return true;
             }
             
          }
            
          else{
          cout<<"  Not found."<<endl;
              return false;
              }    
                
     }

//Clearing the Database and Index_map of Contacts   
void ContactList::clear() 
   {
           database.clear();
              index.clear();
   }

 //Will return a set of Contacts, with the given last name in order   
set<Contact> ContactList::getEntry( const string& aKey ) const throw(NotFoundException)
      {
         //Will check if Entry exists in database
         auto pos =  index.find(aKey);
         //Will find how many Entries of the same last name in the database
         auto key = index.equal_range(aKey);
         //Will create a set of contacts called entryset
         set<Contact> entryset;
         
         if (pos != index.end())
         {
         for (auto it = key.first; it!=key.second; ++it)
         {
            //Will insert the matching entries into the set
            entryset.insert(database.at(it->second));   
         }
         }
            return entryset; 
      }
      
//Will return true if the LastName of the Contact is in the database   
bool ContactList::contains(const string& aKey ) const
     {
        cout<< "Find "<< '"'<< aKey << '"' <<endl;
        auto pos =  index.find(aKey);
        auto key = index.equal_range(aKey);
      if (pos != index.end())
           {
             
      for (auto it = key.first; it!=key.second; ++it){
            cout<<"  Found."<<endl;
            cout<<"  "<<  database.at(it->second).getFirstName() << " " <<
            database.at(it->second).getLastName() << ", " << database.at(it->second).getBirthdate()<<endl;
           }
            return true;
           }
      else{
           cout<<"  Not found."<<endl;
           return false;
          }
        }
        
//Will display the ContactList of the Database in order of last name as modified according to the functions
void ContactList::showList()
   {
      cout<<"Showing contact list:"<<endl;
      
      unsigned count; 
      set<Contact> sameLast;
   //Output the list according to alphabetical order based on last name and then first name if same last name
   for (const auto& it : index) 
      {  
        auto key = index.equal_range(it.first); 
        for(auto it = key.first; it!=key.second; ++it)
        {
           count++;
           sameLast.insert(database.at(it->second));
        }
      }
      if(count > 1)
        {
           for(const auto& a : sameLast)
           {
              cout<<"  ";
              cout<< a.getFirstName() << " " <<
              a.getLastName() << ", "<<
              a.getBirthdate()<<endl;   
           }
        }   
           
        else{ 
         for (const auto& it : index) {  
        
         cout<<"  ";      
         cout<< database.at(it.second).getFirstName() << " " <<
         database.at(it.second).getLastName() << ", "<<
         database.at(it.second).getBirthdate()<<endl;
         }
        }
   
             
   }

//Will display the Final Contact List Unordered  
void ContactList::finalContactList()
    {
       vector<string>birthdate;
       for (unsigned i = 0; i<database.size(); i++) 
      {  
            
       cout<< database.at(i).getFirstName() << "," <<
       database.at(i).getLastName() << ",";
       
        birthdate = split(database.at(i).getBirthdate(), '/');
        cout << birthdate.at(0) <<","<< birthdate.at(1) << "," << birthdate.at(2) <<endl;
        birthdate.clear();
       
      }       
    }
   
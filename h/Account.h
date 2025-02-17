#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <cstring>

using namespace std; 

class Account {
  public: 
    string name; 
    string email; 
    char* password; 
    Account(); 
    Account(string name, string email, const char* password);
    Account(const Account& other); 
    ~Account(); 

  
    Account& operator=(const Account& other);


    void setPassword(const char* newPassword);
};

#endif
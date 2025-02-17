
#include <cstring>

#include "Account.h"

Account::Account() : name("") ,email(""),password(nullptr) {}
Account::Account(const Account& other) 
    :name(other.name),email(other.email) {
        if (other.password) {
            password = new char[strlen(other.password)+ 1];
            strcpy(password , other.password);
        }
        else {
            password = nullptr; 
        }
    }

Account::Account(string name, string email, const char* password) {
    this->name = name;
    this->email = email;
    this->password = new char[strlen(password) + 1];
    strcpy(this->password, password);
}


Account::~Account() {
    delete[] password;
}


Account& Account::operator=(const Account& other) {
    if (this != &other) { 
        name = other.name;
        email = other.email;
        
        delete[] password; 
        password = new char[strlen(other.password) + 1];
        strcpy(password, other.password);
    }
    return *this;
}

void Account::setPassword(const char* newPassword) {
    if(!newPassword) return; 
    delete[] password;
    password = new char[strlen(newPassword)+ 1]; 
    strcpy(password, newPassword);
}
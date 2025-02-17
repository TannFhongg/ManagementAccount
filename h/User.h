#ifndef USER_H 
#define USER_H 

#include "Account.h"
#include <cctype> 
#include <regex>
#include <string>

using namespace std; 

class User { 
    public:  
        static Account accounts[20];  
        static int accountCount;  
    public:
        static void createAccount(); 
        static void forgotPassword();  
        static void login();
     static bool ValidEmail(const string& email);
    static bool ValidPassword(const string& password); 

};


#endif
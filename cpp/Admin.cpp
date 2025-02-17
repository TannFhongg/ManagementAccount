#include "Admin.h"
#include <iostream>
#include "User.h"

using namespace std; 
void Admin::viewAccount() {
    if (User::accountCount == 0) {
        cout << "Khong co tai khoan nao" ; 
        return;
    }
    for (int i = 0; i < User::accountCount; i++) {
       cout << "Name: " << User::accounts[i].name
                  << ", Email: " << User::accounts[i].email
                  << ", Password: " << User::accounts[i].password << "\n";
    }
}

void Admin::deAccount() {
    string name, email;
  cout << "Nhap name: ";
    cin >> name;
   cout << "Nhap email: ";
  cin >> email;

    for (int i = 0; i < User::accountCount; i++) {
        if (User::accounts[i].name == name && User::accounts[i].email == email) {
            for (int j = i; j < User::accountCount - 1; j++) {
                User::accounts[j] = User::accounts[j + 1];
            }
            User::accountCount--;
          cout << "Xoa tai khoan thanh cong" << endl;
            return;
        }
    }

   cout << "Khong tim thay tai khoan" << endl; 
}

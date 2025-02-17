#include "User.h"
#include "Admin.h"

int main() {
    int choice;
    do {
      cout << "Chon 1 : Tao tai khoan" << endl; 
    cout << "Chon 2 : Quen mat khau" << endl; 
    cout << "Chon 3 : Dang nhap" << endl; 
    cout << "Chon 4 : Xem tai khoan"<< endl; 
    cout << "Chon 5 : Xoa tai khoan"<< endl; 
  
   
        std::cin >> choice;

        switch (choice) {
            case 1: User::createAccount(); break;
            case 2: User::forgotPassword(); break;
            case 3: User::login(); break;
            case 4: Admin::viewAccount(); break;
            case 5: Admin::deAccount(); break;
        }
    } while (choice != 0);
    
}

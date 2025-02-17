#include "User.h"
#include <iostream>
#include <regex>
#include <algorithm>

Account User::accounts[20]; 
int User::accountCount = 0;

bool User::ValidEmail(const string& email) {
    return regex_match(email, regex("^[a-zA-Z0-9._%+-]+@gmail\\.com$")); 
}

bool User::ValidPassword(const string& password) {
    return password.length() >= 8 && 
           any_of(password.begin(), password.end(), ::isdigit) && 
           any_of(password.begin(), password.end(), ::islower) && 
           any_of(password.begin(), password.end(), ::isupper) && 
           any_of(password.begin(), password.end(), [](char c) { return ::ispunct(c); });
}

void User::createAccount() {
    if(accountCount >= 20) {
        cout << "Khong the tao them tai khoan" << endl;
        return;
    }

    string name, email, password;
    cout << "Nhap ten tai khoan: ";
    cin >> name;

    cout << "Nhap dia chi email: ";
    cin >> email;
    if (!ValidEmail(email)) {
        cout << "Email khong hop le" << endl;
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].email == email) {
            cout << "Email da ton tai" << endl;
            return;
        }
    }

    cout << "Nhap password: ";
    cin >> password;

    if (!ValidPassword(password)) {
        cout << "Password khong hop le" << endl;
        return;
    }

    accounts[accountCount++] = Account(name, email, password.c_str());
    cout << "Tao tai khoan thanh cong" << endl;
}

void User::forgotPassword() {
    string name, email;
    cout << "Nhap ten tai khoan: ";
    cin >> name;

    cout << "Nhap email: ";
    cin >> email;

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].name == name && accounts[i].email == email) {
            string newPassword;
            cout << "Nhap new password: ";
            cin >> newPassword;

            if (!ValidPassword(newPassword)) {
                cout << "Mat khau moi khong hop le" << endl;
                return;
            }

            accounts[i].setPassword(newPassword.c_str());
            cout << "Mat khau moi da duoc cap nhat" << endl;
            return;
        }
    }

    cout << "Khong tim thay tai khoan" << endl;
}

void User::login() {
    string email, password;
    cout << "Nhap email: ";
    cin >> email;
    cout << "Nhap password: ";
    cin >> password;

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].email == email && strcmp(accounts[i].password, password.c_str()) == 0) {
            cout << "Dang nhap thanh cong hello bro:" << accounts[i].name << "!\n";
            return;
        }
    }

    cout << "Sai email hoac mat khau" << endl;
}

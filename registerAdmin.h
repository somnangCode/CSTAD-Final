#pragma once;
#include <iostream>
#include <string>
#include <vector>
#include "adminManage.h"
#include "hidePin.h"
using namespace std;

//Hospital management system
//options
class Admin{
    public:
        string name = "Admin";
        string pwd = "123456";
        Admin(string name, string password){
            this->name = name;
            this->pwd = password;
        }
        Admin(){

        }
        void login(string username, string password){
            cout << "Enter username: ";
            username;
            cin >> username;
            cout << "Enter password: ";
            password = getHiddenInput();
           
            if(username == name && password == pwd){
                system("cls");
                cout << " ==========================Login successful===========================" << endl;
                secondTab();
            } else {
                cout << "Invalid credentials! Please try again." << endl;
                login(username, password);
            }
        }
};

#include <iostream>
#include <limits>
#include <cctype>
#include <unordered_map>
using namespace std;
#pragma once;
int getValidatedOption() {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 5) {
            cin.clear(); // Clear error flag
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid option. Please input a number!: ";
        } else {
            return choice; 
        }
    }   
}
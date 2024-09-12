#include <iostream>
#include <conio.h>  // For getch()
#pragma once;
using namespace std;

string getHiddenInput() {
    string pin;
    char ch;
    
    while ((ch = _getch()) != '\r') {  // '\r' is the Enter key
        if (ch == '\b') {  // Handle backspace
            if (!pin.empty()) {
                cout << "\b \b";  // Erase the last asterisk
                pin.pop_back();  // Remove last character from the string
            }
        } else {
            pin.push_back(ch);  // Add character to the string
            cout << '*';   // Print asterisk
        }
    }

    cout << endl;  // Move to the next line after Enter is pressed
    return pin;
}


#include <string>
#include <vector>
#include <iostream>
#include "adminOptions.h"
#include "registerAdmin.h"
#include "validation.h"

using namespace std;
int main() {
    system("cls");   
    options();  // Assumed to display options to the user
    cout << "\nEnter your choice: ";
    int choice = getValidatedOption();

    switch (choice) {
        case 1: {
            system("cls");
            Admin admin;
            string username, password;
            cout << "==============================||Admin Log In||==================================" << endl;
            admin.login(username, password);  // Use the username and password to log in
            choose();
            
        }
        case 2: {
            cout << "==============================||Exited||==================================" << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            system("pause");
            main();
        }
    }
    return 0;
}

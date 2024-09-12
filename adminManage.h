#include <string>
#include <iostream>
#include "inputDoctorInfo.h"
#include "adminOptions.h"
using namespace std;
#pragma once;
void secondTab() {
    // Centered content with spaces
    cout << "     ================================================================" << '\n';
    cout << "     ================  Hospital Management System  ==================" << '\n';
    cout << "     =====================  Admin Options  ==========================" << '\n';
    cout << "     ================================================================" << '\n';
    cout << "     ||                    1. Input Doctor Information             ||" << '\n';
    cout << "     ||                    2. Display Appointments                 ||" << '\n';
    cout << "     ||                    3. Search Appointments                  ||" << '\n';
    cout << "     ||                    4. Update Appointments                  ||" << '\n';
    cout << "     ||                    5. Delete Options                       ||" << '\n';
    cout << "     ||                    6. Exit                                 ||" << '\n';
    cout << "     ================================================================" << '\n';
}


void choose(){
    int choice;
    cout << "Choose an option: ";
    cin >> choice;
    switch(choice){
        case 1: {
            Doctor doctor;
            doctor.login();	
            secondTab();
            choose();
        }
        case 6: {
            cout << "Exiting to admin options...!" << endl;
            system("cls");
            options();
        }
        default:
            cout << "Invalid option, please try again." << endl;
    }
}
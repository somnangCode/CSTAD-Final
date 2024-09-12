#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "generateUUID.h"

using namespace std;
#pragma once;
class Doctor {
    private:
        string doctorID;
        string doctorName;
        string doctorSpecialization;
        string doctorTimeAvailable;

    public:
        // Constructor to initialize Doctor object
        Doctor(string ID, string name, string specialization, string timeAvailable) {
            this->doctorID = ID;
            this->doctorName = name;
            this->doctorSpecialization = specialization;
            this->doctorTimeAvailable = timeAvailable;
        }

        // Default constructor
        Doctor() {}

        // Accessor functions to get doctor details
        string getID() const { return doctorID; }
        string getName() const { return doctorName; }
        string getSpecialization() const { return doctorSpecialization; }
        string getTimeAvailable() const { return doctorTimeAvailable; }

        // Function to log in doctors and gather details
        void login() {
            int numDoctors;
            cout << "Enter the number of doctors: ";
            cin >> numDoctors;  
            cin.ignore();  // To ignore the newline character left in the input buffer

            vector<Doctor> doctors;  // Vector to store doctors' information

            for (int i = 0; i < numDoctors; i++) {
                string name, specialization, timeAvailable;
                string doctorID = generateUUID();  // Generate a unique ID for each doctor

                cout << "\n Doctor #"<< (i + 1) << " Details:\n";
                cout << "Doctor Personal UUID: " << doctorID << endl;

                cout << "Doctor's Name: ";
                getline(cin, name);  // Use getline to allow spaces in the input

                cout << "Specialty: ";
                getline(cin, specialization);

                cout << "Time Available: ";
                getline(cin, timeAvailable);

                // Create a new Doctor object and add it to the vector
                Doctor doc(doctorID, name, specialization, timeAvailable);
                doctors.push_back(doc);
            }
            system("cls");
            // Display all doctors' information in a table format
            displayTable(doctors);

        }

        static void displayTable(const vector<Doctor>& doctors) {
            // Print table header
            cout << left << setw(15) << "Doctor UUID" 
                 << setw(20) << "Name"
                 << setw(20) << "Specialty"
                 << setw(20) << "Time Available" << endl;
            cout << string(75, '-') << endl;
            for (const auto& doctor : doctors) {
                cout << left << setw(15) << doctor.getID()
                    << setw(20) << doctor.getName()
                    << setw(20) << doctor.getSpecialization()
                    << setw(20) << doctor.getTimeAvailable() << endl;
            }
            cout << string(75, '-') << endl;  // Separator line
        }

        void search(){
            string name;
            cout << "Search Doc by Name" << endl;
            cout << "Enter Doc Name: ";
            getline(cin, name);
            
        }
};




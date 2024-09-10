#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <limits>
#include <cctype>
#include <random>
#include <sstream>
#include <unordered_map>

using namespace std;

// Global storage for registered patients

void intro(){
      system ("cls");
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
      int i , j;
      for (i=1 ; i<5 ; i++){
            cout << "          ";
            for(j=1 ; j<10 ; j++){
                  if(((i>0)&&(j<3)||(i>0)&&(j>6))){
                        cout <<"    ";
                  }
                  else{
                        SetConsoleTextAttribute(h,4);
                        cout <<"::";
                  }
            }
            cout << endl;
      }
      for (i=0 ; i<7 ; i++){
            cout << "          ";
            for(j=1 ; j<13 ; j++){
                  if(((i>2)&&(j<3)||(i>2)&&(j>6))){
                        cout <<"    ";
                  }
                  else{
                        cout << "::";
                  } 
            }
            cout << endl;
      }
}

//=============================================================================== 

//=============================================================================== 
void patientOption(){
      system ("cls");
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h,10);
      cout << "==============================================" <<endl;
      cout << "========={Hospital Management System}=========" <<endl;
      cout << "===============[Patient Option]===============" <<endl;
      cout << "||           => [1]. Register               ||" <<endl;
      cout << "||           => [2]. Login                  ||" <<endl;
      cout << "||           => [3]. Logout                 ||" <<endl;
      cout << "||           => [0]. Back to Main Menu      ||" <<endl;
      cout << "==============================================" <<endl;
       cout << "=> Please choose an option[0-3]: ";
}

void patientMenu_Login(){
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h,9);
      
      cout << "\n==============================================" <<endl;
      cout << "================{Patient Menu}================" <<endl;
      cout << "==============================================" <<endl;
      cout << "||     => [1]. Book Appionment              ||" <<endl;
      cout << "||     => [2]. View Information             ||" <<endl;
      cout << "||     => [3]. Update Information           ||" <<endl;
      cout << "||     => [4]. Cancel Appionment            ||" <<endl;
      cout << "||     => [0]. Back to Patient Option       ||" <<endl;
      cout << "==============================================" <<endl;
      cout << "=> Please choose an option[0-4]: ";
}

//=============================================================================== 
void MainOption(){
      system ("cls");
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h,12);
      cout << "==============================================" <<endl;
      cout << "========={Hospital Management System}=========" <<endl;
      cout << "===============[ Hospital Menu ]==============" <<endl;
      cout << "||              => [1]. Admin               ||" <<endl;
      cout << "||              => [2]. Patient             ||" <<endl;
      cout << "||              => [0]. Exit                ||" <<endl;
      cout << "==============================================" <<endl;
       cout << "=> Please choose an option[0-2]: ";
}

//=============================================================================== 

uint8_t random8bit() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<uint8_t> dist(0, 255);
    return dist(gen);
}

// Function to convert an integer to a hex string with 2 digits
string to_hex(uint8_t num) {
    stringstream ss;
    ss << hex << setw(2) << setfill('0') << static_cast<int>(num);
    return ss.str();
}

// Function to generate a shortened UUID-like string with only 8 characters
string generateUUID() {
    uint8_t uuid[4];  // Only need 4 bytes to make 8 characters (2 characters per byte)

    // Generate 4 random bytes
    for (int i = 0; i < 4; ++i) {
        uuid[i] = random8bit();
    }

    // Convert to string format
    stringstream ss;
    for (int i = 0; i < 4; ++i) {
        ss << to_hex(uuid[i]);
    }
    return ss.str();
}

//=============================================================================== 
int getValidatedOption() {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 5) {
            cin.clear(); // Clear error flag
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid age. Please try agian!: ";
        } else {
            return choice; 
        }
    }
}

//=============================================================================== 
string getValidatedGender() {
    string gender;
    while (true) {
        cout << " => Enter Gender (M/F): ";
        getline(cin, gender);
        if (gender == "M" || gender == "F") {
            return gender; // Return valid gender
        } else {
            cout << "Invalid gender. Please enter 'M' for Male or 'F' for Female." << endl;
        }
    }
}

string getValidatedSave() {
    string choice;
    while (true) {
        getline(cin, choice);
        if (choice == "S" || choice == "s") {
            return choice; // Return valid gender
        } else {
            cout << "Invalid enter. Please enter 'S' or 's' ." << endl;
        }
    }
}

//=============================================================================== 
int getValidatedAge() {
    int age;
    while (true) {
        cout << " => Enter Age: ";
        cin >> age;
        if (cin.fail() || age < 0 || age > 120) {
            cin.clear(); // Clear error flag
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid age. Please enter a valid age (0-120)" <<endl;
        } else {
            cin.ignore(); 
            return age; 
        }
    }
}

//=============================================================================== 
string getValidatedName() {
    string fullName;
    bool isValid;

    while (true) {
        cout << " => Enter name: ";
        getline(cin, fullName);

        isValid = true;
        if (fullName.empty()) {
            cout << "Name cannot be empty. Please enter a valid name.\n";
            isValid = false;
        } else {
            for (char c : fullName) {
                if (!isalpha(c) && !isspace(c)) {
                    isValid = false;
                    cout << "Invalid name. Only letters and spaces are allowed." << endl;
                    break;
                }
            }
        }

        if (isValid) {
            return fullName; // Return valid name
        }
    }
}

//===============================================================================

class Login {
      protected:
            struct PatientCredentail
            {
                  string passWords;
            };
      
            unordered_map<string , PatientCredentail> patient; // Stores username -> password
            string currentPatient;
      public:
      // Prompt the user to login
      bool loginUserPrompt() {
        string username, password;
        cout << " => Enter username: ";
        cin >> username;
        cout << " => Enter password: ";
        cin >> password;
        return loginPatient(username, password);
    }
            Login() : currentPatient(" "){}
            
            void registerLogin(const string &userName , const string &passWord){
                   if (patient.find(userName) != patient.end()) {
                        cout << "Username already exists." << endl;
                  } else {patient[userName] = {passWord};
                  }
            }

            bool loginPatient(const string& userName, const string& passWord) {
                 
                  if (patient.find(userName) != patient.end() && patient[userName].passWords == passWord) {
                        currentPatient = userName;
                        cout << "Login successful!" << endl;
                        return true;
                 } else {
                        cout << "Invalid username or password." << endl;
                        return loginUserPrompt();
      
                  }
            }

            void logoutPatient() {
                  if (!currentPatient.empty()) {
                        cout << "User " << currentPatient << " logged out." << endl;
                        currentPatient.clear();
                  } else {
                        cout << "No user is logged in." << endl;
                  }
            }

            // Check if a user is logged in
            bool isPatientLogIn() const {
                  return !currentPatient.empty();
            }

            // Get the current logged-in username
            string getCurrentPatient() const {
                  return currentPatient;
            }
};

//=============================================================================== 
class Patient : public Login{
      private:
      struct PatientInformationt
      {
            string uuID;
            string fullName;
            string gender;
            int age;
            int phoneNumber;
            string address;
           
      };
            unordered_map<string,PatientInformationt> patientDetailsInfo;  // Maps username -> PatientInfo
            
      public:
            
            void inputPatientInfo() {
                  string uuID = generateUUID();
                  string fullName;
                  string gender;
                  string userName;
                  string passWord;
                  int age;
                  int phoneNumber;
                  string address;
                  string uUID;
                  string choice;

                  cout << "----------------------------------------------" << endl;
                  cout << "|             Input Information              |" << endl;
                  cout << "----------------------------------------------" << endl;
                  cin.ignore();
                  fullName = getValidatedName(); // get name();
                  gender = getValidatedGender(); // get gender();
                  age = getValidatedAge(); // get age();
                  cout << " => Enter Phone Number(+885): ";
                  cin >> phoneNumber;
                  cin.ignore();
                  cout << " => Enter Address: ";
                  getline(cin , address);
                   cout << "----------------------------------------------" << endl;
                  cout << " => Create username: ";
                  getline(cin , userName);
                  cout << " => Create password: ";
                  getline(cin , passWord);
                  registerLogin(userName , passWord);
                  cout << "----------------------------------------------" << endl;
                  patientDetailsInfo[userName] = PatientInformationt{uUID , fullName, gender , age , phoneNumber , address};
                  cout << "Patient registered successfully!" << endl;
                  cout << "----------------------------------------------" << endl;
            }

            void displayPatient() {
                  if (isPatientLogIn()) {
                  const PatientInformationt& info = patientDetailsInfo[getCurrentPatient()];
                        cout << endl;
                        cout << "=================[ Patient Informatiot ]==============" << endl;
                        cout << "UUID: " << generateUUID()<< endl;
                        cout << "Name: " << info.fullName << endl;
                        cout << "Gender: " << info.gender << endl;
                        cout << "Age: " << info.age << endl;
                        cout << "Phone Number: " << info.phoneNumber << endl;
                        cout << "Address: " << info.address << endl;
                        //cout << "Appointment Date: " << (info.appointmentDate.empty() ? "None" : info.appointmentDate) << endl;
                  } else {
                        cout << "Please log in first to display information." << std::endl;
                  }               
            }

            void postLoginMenu(){
                  int choice;
                  do{
                        patientMenu_Login();
                        choice = getValidatedOption();
                        system("cls");
                        switch(choice){
                              case 1:{
                                               
                                    break;
                              }
                              case 2:{
                                    displayPatient();
                                    break;
                              }
                              case 3:{
                                               
                                    break;
                              }
                              case 4:{
                                    logoutPatient();
                                    break;
                              }
                              case 0:{
                                    
                                    break;
                              }
                              default:

                              break;
                        }
                        if(true){
                        cout << "Press key enter to continue....";
                        cin.get();
                        }
                  }while(choice != 0);
            }
      
            void postPatientOption(){
                  int choice;
                 
                  do{
                        patientOption();
                        choice = getValidatedOption();
                        system("cls");
                        switch(choice){
                              case 1:{
                                    inputPatientInfo();
                                    break;
                              }
                              case 2:{
                                    if (!loginUserPrompt()) return; 
                                         postLoginMenu(); 
                                    break;
                              }
                              case 3:{
                               cout << "Logged out successfully." << endl;
                                    break;
                              }
                              case 0:{
                                    exit (0);
                                    cout << "Exit program...." << endl;
                                    break;
                              }
                              default:
                                    cout << "Invalid choice. Please try again.\n";
                         break;
                        }

                        if(true){
                              cout << "Press key enter to continue...." << endl;
                              cin.get();
                        }
                  }while(choice != 0);

                  logoutPatient();
            }

      public:
      
};

class Hospital_Management_System{
      public:
      
      

};

class Appionment{

};

int main(){
      system("cls");
      intro();

      Patient patients;
      patients.postPatientOption();
//=========================================================================
      return 0;
}
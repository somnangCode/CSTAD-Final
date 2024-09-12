#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Function to save integers to a file
void saveToFile(const vector<int>& numbers, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int number : numbers) {
            outFile << number << endl;
        }
        outFile.close();
        cout << "Data saved to " << filename << endl;
    } else {
        cout << "Unable to open file for writing!" << endl;
    }
}

// Function to load integers from a file
vector<int> loadFromFile(const string& filename) {
    vector<int> numbers;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        int number;
        while (inFile >> number) {
            numbers.push_back(number);
        }
        inFile.close();
        cout << "Data loaded from " << filename << endl;
    } else {
        cout << "Unable to open file for reading!" << endl;
    }
    return numbers;
}

// Function to display integers
void displayNumbers(const vector<int>& numbers) {
    cout << "Numbers loaded from file:" << endl;
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;
}

int main() {
    const string filename = "numbers.txt";
    cout << 
    vector<int> userNumbers;

    // Get user input
    int num;
    char continueInput;
    do {
        cout << "Enter an integer: ";
        cin >> num;
        userNumbers.push_back(num);

        cout << "Do you want to enter another integer? (y/n): ";
        cin >> continueInput;
    } while (continueInput == 'y' || continueInput == 'Y');

    // Save user input to a file
    saveToFile(userNumbers, filename);

    // Load integers from the file and display them
    vector<int> loadedNumbers = loadFromFile(filename);
    displayNumbers(loadedNumbers);

    return 0;
}

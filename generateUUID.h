#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

using namespace std;

// Function to generate a random 8-bit integer
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



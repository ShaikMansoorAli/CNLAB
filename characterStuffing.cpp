#include <iostream>
#include <string>
using namespace std;


string characterStuffing(const string &data, char flag, char esc) {
    string stuffed = "";
    for (char ch : data) {
        if (ch == flag || ch == esc)
            stuffed += esc;  
        stuffed += ch;
    }
    return stuffed;
}

int main() {
    string data;
    char FLAG, ESC;

    
    cout << "Enter the data to send: ";
    getline(cin, data);  

    cout << "Enter the FLAG character: ";
    cin >> FLAG;

    cout << "Enter the ESC (escape) character: ";
    cin >> ESC;

    
    string stuffed = characterStuffing(data, FLAG, ESC);

    cout << "\n=== SENDER SIDE ===";
    cout << "\nOriginal Data: " << data;
    cout << "\nStuffed Data:  " << FLAG << stuffed << FLAG << endl;

    
    string received = stuffed;  
    string unstuffed = "";

    for (size_t i = 0; i < received.size(); i++) {
        if (received[i] == ESC && (received[i + 1] == FLAG || received[i + 1] == ESC)) {
            
            continue;
        }
        unstuffed += received[i];
    }

    cout << "\n=== RECEIVER SIDE ===";
    cout << "\nUnstuffed Data: " << unstuffed << endl;

    return 0;
}

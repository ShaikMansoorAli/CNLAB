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

string characterUnstuffing(const string &stuffed, char flag, char esc) {
    string unstuffed = "";
    for (size_t i = 0; i < stuffed.size(); i++) {
        if (stuffed[i] == esc && (i + 1 < stuffed.size()) &&
            (stuffed[i + 1] == flag || stuffed[i + 1] == esc)) {
            continue; 
        }
        unstuffed += stuffed[i];
    }
    return unstuffed;
}

string bitStuffing(const string &data) {
    string stuffed = "";
    int count = 0;
    for (char bit : data) {
        stuffed += bit;
        if (bit == '1') {
            count++;
            if (count == 5) {  
                stuffed += '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return stuffed;
}

string bitUnstuffing(const string &stuffed) {
    string unstuffed = "";
    int count = 0;
    for (size_t i = 0; i < stuffed.size(); i++) {
        unstuffed += stuffed[i];
        if (stuffed[i] == '1') {
            count++;
            if (count == 5 && i + 1 < stuffed.size() && stuffed[i + 1] == '0') {
                i++; 
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return unstuffed;
}

int main() {
    int choice;
    cout << "====== FRAME STUFFING TECHNIQUES ======\n";
    cout << "1. Character Stuffing\n";
    cout << "2. Bit Stuffing\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore(); 
    if (choice == 1) {
        
        string data;
        char FLAG, ESC;

        cout << "\nEnter the data to send: ";
        getline(cin, data);

        cout << "Enter the FLAG character: ";
        cin >> FLAG;

        cout << "Enter the ESC (escape) character: ";
        cin >> ESC;

        string stuffed = characterStuffing(data, FLAG, ESC);
        string unstuffed = characterUnstuffing(stuffed, FLAG, ESC);

        cout << "\n=== SENDER SIDE ===";
        cout << "\nOriginal Data: " << data;
        cout << "\nStuffed Data:  " << FLAG << stuffed << FLAG << endl;

        cout << "\n=== RECEIVER SIDE ===";
        cout << "\nUnstuffed Data: " << unstuffed << endl;
    }

    else if (choice == 2) {
        
        string data;
        cout << "\nEnter the bit stream (e.g. 011111101111110): ";
        cin >> data;

        string stuffed = bitStuffing(data);
        string unstuffed = bitUnstuffing(stuffed);

        cout << "\n=== SENDER SIDE ===";
        cout << "\nOriginal Bits:  " << data;
        cout << "\nStuffed Bits:   " << stuffed << endl;

        cout << "\n=== RECEIVER SIDE ===";
        cout << "\nUnstuffed Bits: " << unstuffed << endl;
    }

    else {
        cout << "Invalid choice! Please run again.\n";
    }

    return 0;
}

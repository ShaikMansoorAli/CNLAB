#include <iostream>
#include <string>
using namespace std;

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
    string data = "011111101111110";
    string stuffed = bitStuffing(data);
    string unstuffed = bitUnstuffing(stuffed);

    cout << "Original:  " << data << endl;
    cout << "Stuffed:   " << stuffed << endl;
    cout << "Unstuffed: " << unstuffed << endl;
}

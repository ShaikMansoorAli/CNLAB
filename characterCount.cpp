#include <iostream>
#include <string>
using namespace std;


string createFrame(const string &data) {
    int count = data.size();
    return to_string(count) + data; 
}
int main() {
    string data;

    cout << "Enter data to send: ";
    getline(cin, data);  

    string frame = createFrame(data);

    cout << "\n=== SENDER SIDE ===";
    cout << "\nFrame sent: " << frame << endl;

    
    int count = frame[0] - '0';  
    string receivedData = frame.substr(1, count);

    cout << "\n=== RECEIVER SIDE ===";
    cout << "\nCount extracted: " << count;
    cout << "\nReceived Data: " << receivedData << endl;

    return 0;
}

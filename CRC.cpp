#include <iostream>
#include <string>
using namespace std;


string xorDivision(string dividend, string divisor) {
    int n = divisor.length();

    for (int i = 0; i <= dividend.length() - n; ) {
        
        if (dividend[i] == '1') {
            for (int j = 0; j < n; j++)
                dividend[i + j] = (dividend[i + j] == divisor[j]) ? '0' : '1';
        }
        
        while (i < dividend.length() && dividend[i] != '1')
            i++;
    }

    
    return dividend.substr(dividend.length() - (n - 1));
}

int main() {
    string data, generator;

    cout << "Enter binary dataword: ";
    cin >> data;

    cout << "Enter generator polynomial (binary): ";
    cin >> generator;

    int m = generator.length();
    string appendedData = data + string(m - 1, '0');

    
    string remainder = xorDivision(appendedData, generator);
    string codeword = data + remainder;

    cout << "\n===== SENDER SIDE =====";
    cout << "\nDataword:  " << data;
    cout << "\nGenerator: " << generator;
    cout << "\nRemainder: " << remainder;
    cout << "\nTransmitted Codeword: " << codeword << endl;

    
    string received;
    cout << "\nEnter received codeword (to check for errors): ";
    cin >> received;

    string check = xorDivision(received, generator);

    cout << "\n===== RECEIVER SIDE =====";
    cout << "\nRemainder after division: " << check;

    if (check.find('1') == string::npos)
        cout << "\nNo error detected in transmission.\n";
    else
        cout << "\n Error detected in received frame.\n";

    return 0;
}

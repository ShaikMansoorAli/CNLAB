#include <iostream>
#include <string>
using namespace std;

string xorEncryptDecrypt(string text, char key) {
    string output = text;
    for (size_t i = 0; i < text.size(); i++) {
        output[i] = text[i] ^ key; 
    }
    return output;
}

int main() {
    string text;
    char key;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter single-character key: ";
    cin >> key;

    string encrypted = xorEncryptDecrypt(text, key);
    string decrypted = xorEncryptDecrypt(encrypted, key);

    cout << "\nEncrypted: " << encrypted;
    for (unsigned char c : encrypted)
        cout << (int)c << " ";
    cout << "\nDecrypted: " << decrypted << endl;
    return 0;
}

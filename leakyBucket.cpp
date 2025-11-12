#include <iostream>
#include <vector>
using namespace std;

int minValue(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int bucket_size, output_rate, n;

    cout << "Enter bucket size (in packets): ";
    cin >> bucket_size;

    cout << "Enter output rate (packets/tick): ";
    cin >> output_rate;

    cout << "Enter number of incoming packet bursts (ticks): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of bursts!" << endl;
        return 0;
    }

    vector<int> incoming(n);
    cout << "Enter number of packets in each burst:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> incoming[i];
    }

    cout << "\n--- Leaky Bucket Simulation ---\n";

    int stored_packets = 0;

    for (int i = 0; i < n; i++) {
        int dropped = 0;
        int transmit = 0;

        cout << "\nBurst " << (i + 1) << ":\n";
        cout << "Incoming packets = " << incoming[i] << endl;

        
        if (incoming[i] + stored_packets > bucket_size) {
            dropped = (incoming[i] + stored_packets) - bucket_size;
            stored_packets = bucket_size;
            cout << "Bucket overflow! Dropped packets = " << dropped << endl;
        } else {
            stored_packets += incoming[i];
        }

        cout << "Packets in bucket before transmission = " << stored_packets << endl;

        
        transmit = minValue(stored_packets, output_rate);
        stored_packets -= transmit;
        cout << transmit << " packets transmitted." << endl;
        cout << "Packets left in bucket = " << stored_packets << endl;
    }

    
    while (stored_packets > 0) {
        int transmit = minValue(stored_packets, output_rate);
        stored_packets -= transmit;
        cout << transmit << " packets transmitted (draining bucket)..." << endl;
    }

    cout << "\nTransmission complete. Bucket empty.\n";
    return 0;
}

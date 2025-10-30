#include <iostream>
#include <unistd.h> 
using namespace std;

int main() {
    int bucket_size, output_rate, n;

    cout << "Enter bucket size (in packets): ";
    cin >> bucket_size;
    cout << "Enter output rate (packets/sec): ";
    cin >> output_rate;
    cout << "Enter number of incoming packet bursts: ";
    cin >> n;

    int incoming[n];
    cout << "Enter number of packets in each burst:\n";
    for (int i = 0; i < n; i++)
        cin >> incoming[i];

    int stored_packets = 0;

    cout << "\n--- Leaky Bucket Simulation ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nBurst " << i + 1 << ":\n";
        cout << "Incoming packets = " << incoming[i] << endl;

        
        if (incoming[i] + stored_packets > bucket_size) {
            int dropped = (incoming[i] + stored_packets) - bucket_size;
            stored_packets = bucket_size;
            cout << "Bucket overflow! Dropped packets = " << dropped << endl;
        } else {
            stored_packets += incoming[i];
        }

        cout << "Packets in bucket before transmission = " << stored_packets << endl;

        
        sleep(1); 
        if (stored_packets >= output_rate) {
            stored_packets -= output_rate;
            cout << output_rate << " packets transmitted.\n";
        } else {
            cout << stored_packets << " packets transmitted.\n";
            stored_packets = 0;
        }

        cout << "Packets left in bucket = " << stored_packets << endl;
    }

    
    while (stored_packets > 0) {
        sleep(1);
        if (stored_packets >= output_rate) {
            stored_packets -= output_rate;
            cout << output_rate << " packets transmitted (draining bucket)...\n";
        } else {
            cout << stored_packets << " packets transmitted (final drain)...\n";
            stored_packets = 0;
        }
    }

    cout << "\n Transmission complete. Bucket empty.\n";
    return 0;
}

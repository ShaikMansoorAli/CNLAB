#include <iostream>
using namespace std;

struct Frame {
    int id;     
    int seq_no;  
};

int main() {
    int n;
    cout << "Enter number of frames received: ";
    cin >> n;

    Frame frames[50]; 
    cout << "\nEnter details for each frame as: ID,  Seq.no\n";
    for (int i = 0; i < n; i++) {
        cout << "Frame " << i + 1 << ": ";
        cin >> frames[i].id >> frames[i].seq_no;
    }

    cout << "\nFrames before sorting (arrival order):\n";
    cout << "FrameID\tSeqNo\n";
    for (int i = 0; i < n; i++)
        cout << frames[i].id << "\t" << frames[i].seq_no << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (frames[j].seq_no > frames[j + 1].seq_no) {
                Frame temp = frames[j];
                frames[j] = frames[j + 1];
                frames[j + 1] = temp;
            }
        }
    }

    cout << "\nFrames after sorting (by Sequence Number):\n";
    cout << "FrameID\tSeqNo\n";
    for (int i = 0; i < n; i++)
        cout << frames[i].id << "\t" << frames[i].seq_no << endl;

    cout << "\n (Sequence Number Sorted)\n";

    return 0;
}

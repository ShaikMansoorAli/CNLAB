#include <iostream>
#include <cstdlib>
using namespace std;


void goBackN(int total_frames, int window_size, int loss_percent, unsigned int seed) {
    int next_frame_to_send = 0;

    if (window_size <= 0) {
        cout << "Window size must be positive.\n";
        return;
    }
    if (total_frames <= 0) {
        cout << "Nothing to send.\n";
        return;
    }
    if (loss_percent < 0) loss_percent = 0;
    if (loss_percent > 100) loss_percent = 100;

    srand(seed);

    cout << "\nSimulating Go-Back-N Protocol...\n";
    cout << "Total Frames: " << total_frames
         << " | Window Size: " << window_size
         << " | Loss Probability: " << loss_percent << "%"
         << " | RNG Seed: " << seed << "\n\n";

    while (next_frame_to_send < total_frames) {
        int frame_end = next_frame_to_send + window_size;
        if (frame_end > total_frames)
            frame_end = total_frames;

        int window_len = frame_end - next_frame_to_send;
        int frame_lost_flag = 0;
        int lost_frame = -1;

        cout << "Sending frames: ";
        for (int i = next_frame_to_send; i < frame_end; i++)
            cout << i << " ";
        cout << "\n";

        if (window_len > 0) {
            int r = rand() % 100; 
            if (r < loss_percent) {
                frame_lost_flag = 1;
                lost_frame = next_frame_to_send + (rand() % window_len);
            }
        }

        if (frame_lost_flag) {
            cout << " Frame " << lost_frame << " lost during transmission!\n";
            cout << " Timeout occurred. Resending frames from "
                 << lost_frame << " onwards...\n\n";
            next_frame_to_send = lost_frame;
        } else {
            cout << " All frames from " << next_frame_to_send
                 << " to " << frame_end - 1 << " acknowledged.\n\n";
            next_frame_to_send = frame_end; // Slide window
        }

     
    }

    cout << "All frames successfully transmitted and acknowledged!\n";
}

int main() {
    int total_frames, window_size, loss_percent;
    unsigned int seed;

    cout << "Enter total number of frames: ";
    cin >> total_frames;

    cout << "Enter window size: ";
    cin >> window_size;

    cout << "Enter frame loss probability (0-100): ";
    cin >> loss_percent;

    cout << "Enter RNG seed (e.g., 1234): ";
    cin >> seed;

    goBackN(total_frames, window_size, loss_percent, seed);
    return 0;
}

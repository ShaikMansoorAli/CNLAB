#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  

void goBackN(int total_frames, int window_size) {
    int next_frame_to_send = 0;

    srand(time(0)); 

    printf("\nSimulating Go-Back-N Protocol...\n");
    printf("Total Frames: %d | Window Size: %d\n\n", total_frames, window_size);

    while (next_frame_to_send < total_frames) {
        int frame_end = next_frame_to_send + window_size;
        if (frame_end > total_frames)
            frame_end = total_frames;

        printf("Sending frames: ");
        for (int i = next_frame_to_send; i < frame_end; i++) {
            printf("%d ", i);
        }
        printf("\n");

        
        int lost_frame = next_frame_to_send + rand() % (frame_end - next_frame_to_send);
        int frame_lost = rand() % 4 == 0;

        if (frame_lost) {
            printf(" Frame %d lost during transmission!\n", lost_frame);
            printf("Timeout occurred. Resending frames from %d onwards...\n\n", lost_frame);
            next_frame_to_send = lost_frame; 
            sleep(1);
        } else {
            printf(" All frames from %d to %d acknowledged.\n\n", next_frame_to_send, frame_end - 1);
            next_frame_to_send = frame_end;
            sleep(1);
        }
    }

    printf(" All frames successfully transmitted and acknowledged!\n");
}

int main() {
    int total_frames, window_size;

    printf("Enter total number of frames: ");
    scanf("%d", &total_frames);
    printf("Enter window size: ");
    scanf("%d", &window_size);

    goBackN(total_frames, window_size);

    return 0;
}

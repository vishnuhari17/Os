#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, i, j, head, movement = 0, initial, final, closest_index, closest_distance;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n], served[n];

    printf("Enter the processes: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &process[i]);
        served[i] = 0;  // Initialize served array to keep track of serviced requests
    }

    printf("Enter the head position: ");
    scanf("%d", &head);

    initial = head;

    printf("The processes are: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", process[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        // Find the closest unserved request
        closest_distance = abs(head - process[0]);
        closest_index = -1;
        for (j = 0; j < n; j++) {
            if (!served[j]) {
                int distance = abs(head - process[j]);
                if (closest_index == -1 || distance < closest_distance) {
                    closest_distance = distance;
                    closest_index = j;
                }
            }
        }

        // Serve the closest request
        if (closest_index != -1) {
            final = process[closest_index];
            printf("Process %d served\n", final);
            movement += abs(final - initial);
            initial = final;
            head = final;
            served[closest_index] = 1;  // Mark the request as served
        }
    }

    printf("The total head movement was: %d\n", movement);
}


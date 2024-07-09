#include <stdio.h>

void main() {
    int n, i, j, process[50], head, movement = 0, initial, final, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the processes: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }
    printf("Enter the head position: ");
    scanf("%d", &head);

    initial = head;

    // Sort the process array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (process[j] > process[j + 1]) {
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }

    printf("The processes are: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", process[i]);
    }
    printf("\n");

    // Move to the right until the end and then reverse
    for (i = 0; i < n; i++) {
        if (process[i] >= head) {
            break;
        }
    }

    // Service requests to the right of the head
    for (; i < n; i++) {
        final = process[i];
        printf("Process %d served\n", final);
        movement += abs(final - initial);
        initial = final;
    }

    // Reverse direction and service the remaining requests
    for (i = n - 1; i >= 0; i--) {
        if (process[i] < head) {
            final = process[i];
            printf("Process %d served\n", final);
            movement += abs(final - initial);
            initial = final;
        }
    }

    printf("The total head movement was: %d\n", movement);
}


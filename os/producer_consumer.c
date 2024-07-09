#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

// Declare semaphores and shared variables
sem_t mutex, empty, full;
int buffer[5], get = 0, item = 0, gitem, put = 0, pro[20], con[20];

void *producer(void *arg)
{
    do
    {
        // Wait until there is an empty slot in the buffer
        sem_wait(&empty);
        // Wait to acquire the mutex (semaphore) lock
        sem_wait(&mutex);
        // Place the produced item into the buffer
        buffer[put % 5] = item;
        // 'arg' is a pointer to an integer, so type casting is required to get the value
        printf("Producer %d : produced item %d in buffer, buffer[%d] = %d\n", (*(int *)arg), buffer[put % 5], put % 5, item);
        // Increment the item and buffer index
        item++;
        put++;
        // Release the mutex (semaphore) lock
        sem_post(&mutex);
        // Signal that there is a full slot in the buffer
        sem_post(&full);
        // Sleep for 3 seconds to simulate production time
        sleep(3);
    }
    while (put < 5);  // Run until 5 items are produced
}

void *consumer(void *arg)
{
    do
    {
        // Wait until there is a full slot in the buffer
        sem_wait(&full);
        // Wait to acquire the mutex (semaphore) lock
        sem_wait(&mutex);
        // Consume the item from the buffer
        gitem = buffer[get % 5];
        // 'arg' is a pointer to an integer, so type casting is required to get the value
        printf("Consumer %d : consumed item %d in buffer, buffer[%d] : %d\n", (*(int *)arg), gitem, get % 5, gitem);
        // Increment the buffer index
        get++;
        // Release the mutex (semaphore) lock
        sem_post(&mutex);
        // Signal that there is an empty slot in the buffer
        sem_post(&empty);
        // Sleep for 2 seconds to simulate consumption time
        sleep(2);
    }
    while (get < 5);  // Run until 5 items are consumed
}

void main()
{
    int p, c, j, k;
    pthread_t a[10], b[10];

    // Initialize semaphores: &mutex is the semaphore name, 0 means shared between threads of the same process, 1 is the initial value
    sem_init(&mutex, 0, 1);
    // Initialize full semaphore to 0 (no full slots initially)
    sem_init(&full, 0, 0);
    // Initialize empty semaphore to 5 (all slots are empty initially)
    sem_init(&empty, 0, 5);

    printf("\nEnter number of producers : ");
    scanf("%d", &p);
    printf("\nEnter number of consumers : ");
    scanf("%d", &c);

    // Create producer threads
    for (j = 0; j < p; j++)
    {
        pro[j] = j;
        pthread_create(&a[j], NULL, producer, &pro[j]);
    }

    // Create consumer threads
    for (k = 0; k < c; k++)
    {
        con[k] = k;
        pthread_create(&b[k], NULL, consumer, &con[k]);
    }

    // Wait for all producer threads to finish
    for (j = 0; j < p; j++)
        pthread_join(a[j], NULL);

    // Wait for all consumer threads to finish
    for (k = 0; k < c; k++)
        pthread_join(b[k], NULL);
}


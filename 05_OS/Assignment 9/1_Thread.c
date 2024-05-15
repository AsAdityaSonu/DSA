#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

int data[] = {45, 56, 78, 32, 9, 5};

// Thread Function to calculate sum of data
void *calculate_sum(void *arg) {
    int *thread_id = (int *)arg;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += data[i];
        sleep(1);
    }
    printf("Thread %d Sum of data is %d\n", *thread_id, sum);
    pthread_exit(NULL);
}

// Thread function to find maximum of data
void *find_max(void *arg) {
    int *thread_id = (int *)arg;
    int max = data[0];
    for (int i = 0; i < 5; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    printf("Thread %d Maximum of data is %d\n", *thread_id, max);
    pthread_exit(NULL);
}

// Thread function to find minimum of data
void *find_min(void *arg) {
    int *thread_id = (int *)arg;
    int min = data[0];
    for (int i = 0; i < 5; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    printf("Thread %d Minimum of data is %d\n", *thread_id, min);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_id[NUM_THREADS], i;

    // Initialize with thread IDs
    for (i = 0; i < NUM_THREADS; i++) {
        thread_id[i] = i;
    }

    // Creating threads
    pthread_create(&threads[0], NULL, calculate_sum, (void *)&thread_id[0]);
    pthread_create(&threads[1], NULL, find_max, (void *)&thread_id[1]);
    pthread_create(&threads[2], NULL, find_min, (void *)&thread_id[2]);

    // Main thread waits for these threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

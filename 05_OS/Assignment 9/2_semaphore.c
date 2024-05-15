#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int common_variable =10;

sem_t semaphore;
void *Incre(void *arg){
    int *thread_id = ((int *)arg);

    // Wait on semaphore (Increment it)
    sem_wait(&semaphore);
    int i = common_variable;

    // Critical section
    i++;
    sleep(1);
    common_variable = i;
    printf("Thread %d: %d\n", thread_id, common_variable);

    // Signal on semaphore (Decrement it)
    sem_post(&semaphore);
    pthread_exit(NULL);

}

void *Decre(void *arg){
    int thread_id = *((int *)arg);

    // Wait on semaphore (Decrement it)
    sem_wait(&semaphore);
    int i = common_variable;

    // Critical section
    i--;
    sleep(5);
    common_variable = i;
    printf("Thread %d: %d\n", thread_id, common_variable);

    // Signal on semaphore (Increment it)
    sem_post(&semaphore);
    pthread_exit(NULL);
}

int main(){
    sem_init(&semaphore, 0, 1);
    pthread_t t1, t2;

    int t1_id =1;
    int t2_id =2;

    // Creating two threads
    pthread_create(&t1, NULL, &Incre, (void *)&t1_id);
    pthread_create(&t2, NULL, &Decre, (void *)&t2_id);

    // Joining two threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaphore);

    printf("Final common variable value %d\n ",common_variable);
    return 0;
}
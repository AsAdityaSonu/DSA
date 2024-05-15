#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define max 3

int data[] = {1,2,3,4,4,5,6};

void* add(int arg){
    int *thread_id = (int*)arg;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += data[i];
        printf("%d\n",sum);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main(){
    pthread_t thread[3];
    int thread_id[3];

    for(int i =0 ;i<3;i++){
        thread_id[i] =i;
    }

    pthread_create(&thread[0], NULL, add, (void*)thread_id);

    for(int i =0;i<3;i++){
        pthread_join(thread[i], NULL);
    }
}
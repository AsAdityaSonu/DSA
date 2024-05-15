#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<semaphore.h>
#define MSGSIZE 16

int VAR =10;
sem_t semaphore;

int main(){
    char inbuf[MSGSIZE];
    int fd[2];
    sem_init(&semaphore, 0, 0);
    pipe(fd);
    pid_t pid = fork();

    if(pid ==-1){
        perror("Fork failed");
        exit(1);
    }else if(pid == 0){
        sleep(2);
        VAR = VAR -2;
        printf("child process: shared variable = %d\n", VAR);
        sem_post(&semaphore);    //sem_post increments (unlocks the semaphore by pointed to by sem)
        write(fd[1],"1",2);
    }else{
        read(fd[0],inbuf,MSGSIZE);
        sem_init(&semaphore, 0, atoi(inbuf));
        sem_wait(&semaphore);   // sem_wait decrements (locks the semaphore by pointed to by sem)
        VAR = VAR +2;
        printf("parent process: shared variable = %d\n", VAR);
        sem_destroy(&semaphore);
        return 0;
    }
}

// gcc filename.c -0 filename -lp thread
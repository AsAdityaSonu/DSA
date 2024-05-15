// #include <stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// int main()
// {
//     int fd[2], n;
//     char buffer[100];
//     pid_t p;
//     pipe(fd); // creates a unidirectional pipe with two end fd[0] and fd[1]
//     p = fork();
//     if (p > 0) // parent
//     {
//         printf("Parent Passing value to child\n");
//         write(fd[1], "hello\n", 6); // fd[1] is the write end of the pipe
//         sleep(3);
//     }
//     else // child
//     {
//         printf("Child printing received value\n");
//         n = read(fd[0], buffer, 100); // fd[0] is the read end of the pipe
//         printf("%s", buffer);
//         write(1, buffer, n);
//     }
// }

#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int fd[2],n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p = fork();

    if(p>0){
        printf("Printing the parents\n");
        write(fd[1],"hello\n",6);
        sleep(3);
    }else{
        printf("Printing the child\n");
        n = read(fd[0],buffer,100);
        printf("%s",buffer);
        write(1,buffer,n);
    }
}
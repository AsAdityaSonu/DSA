// // Writer Process
// #include<stdio.h>
// #include<sys/ipc.h>
// #include<sys/msg.h>
// #define MAX 10

// struct mesg_buffer{
//     long mesg_type;
//     char mesg_text[100];
// }message;

// int main(){
//     key_t key;
//     int msgid;

//     // Generate Unique Key
//     key = ftok("msg_queue.c",65);

//     //msgget creates a message queue
//     msgid = msgget(key,0666|IPC_CREAT);
//     message.mesg_type = 1;

//     printf("Write data: ");
//     fgets(message.mesg_text,MAX,stdin);

//     msgsnd(msgid,&message,sizeof(message),0);

//     printf("Data Sent: %s",message.mesg_text);
//     return 0;

// }

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10

struct msg_buffer{
    long msg_type;
    char msg_text[100];
}m;

int main(){
    key_t key;
    int msgid;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666|IPC_CREAT);
    m.msg_type=1;

    printf("Enter the message: ");
    fgets(m.msg_text,MAX,stdin);

    msgsnd(msgid,&m, sizeof(m), 0);
    printf("Message sent\n");
    return 0;

}
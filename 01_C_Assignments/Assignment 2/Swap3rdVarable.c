#include<stdio.h>
int main(){
    printf("Enter any two numbers... \n");
    //Declaraion
    int c,d,x;
    //Data Input
    scanf("%d%d",&c,&d);

    x= c+d;
    c= x-c;
    d= x-d;

    //Data Output after Swaping values
    printf("The new value of c is: %d\n",c);
    printf("The new value of d is: %d\n",d);

    return 0;
}
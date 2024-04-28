#include<stdio.h>
int main(){
    printf("Enter any number you wants to check.");
    int check;
    scanf("%d",&check);

    (check%2)==0? printf("It is a even number") : printf("It is a odd number");

    return 0;

}
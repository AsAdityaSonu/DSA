#include<stdio.h>
int main(){
    int num;
    printf("Enter any value you wants to check.");
    scanf("%d",&num);

    (num%2==0)? printf("The given number is an Even number") : printf("The given number is a odd number.");
}
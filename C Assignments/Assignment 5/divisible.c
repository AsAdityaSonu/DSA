#include<stdio.h>
int main(){
    int num;
    printf("Enter any umber you wants to check:");
    scanf("%d",&num);

    //operation part
    if (num % 5==0 && num % 8 ==0)
    {
        /* code */
        printf("The number is exactly divisible by both 5 and 8.");
    }else if(num%8==0)
    {
        printf("The number is exactly divisible by 8.");
    }else if (num%5==0)
    {
        printf("The number is exactly divisible by 5.");
    }
    
}
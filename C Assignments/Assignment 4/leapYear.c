//divisible by 4 but not by 100
//divisible by both 100 and 400
#include <stdio.h>
int main(){
    int num;
    printf("Enter any year you wants to check: ");
    scanf("%d",&num);
    if (num%100==0 && num%400==0 || num%4==0 && num%100!=0)
    {
        /* code */
        printf("The given year is a leap year.");
    }else{
        printf("The given year is not a leap year.");
    }
    
}
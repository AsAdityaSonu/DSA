#include<stdio.h>
#include<math.h>
int main(){
    //data input
    int num,num1,rem,sum=0;
    printf("Enter any value you wants to check: ");
    scanf("%d",&num);

    //operation part
    num1=num;

    while (num1!=0)
    {
        /* code */
        rem= num1%10;
        sum=sum+pow(rem,3);
        num1/=10;
    }
    if (sum == num)
    {
        /* code */
        printf("The given number is a Armstrong number.");
    }else{
        printf("The given number is not a Armstring number.");
    }
    
    
}
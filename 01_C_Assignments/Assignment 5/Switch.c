#include<stdio.h>
int main(){
    int num1,num2,oper;
    //data input
    printf("Enter any value:");
    scanf("%d",&num1);
    printf("Enter any second value:");
    scanf("%d",&num2);
    printf("1.Addition \n2.Subtraction \n3.Multiplication \n4.Division\n");
    printf("Enter any number from above operations:");
    scanf("%d",&oper);

    //operation
    switch (oper)
    {
    case 1:
        printf("The value after addition of both numbers is %d",num1+num2);
        break;
    case 2:
        printf("The value after subration of both numbers is %d",num1-num2);
        break;
    case 3:
        printf("The value after multiplication of both numbers is %d",num1*num2);
        break;
    case 4:
        printf("The value after division of both the numbers is %.2f",(float)num1/num2);
    default:
        break;
    }


}
#include<stdio.h>
void main(){
    int num1, num2;
    double div;
    printf("Enter any two numbers\n");
    printf("_____________________\n");
    printf("Enter first number:\n");
    scanf("%d",&num1);
    printf("Enter second number:\n");
    scanf("%d",&num2);

    div =(double)(num1+num2)/2;

    printf("Mean of two number using type casting %.2lf\n\a",div);
    printf("%d",sizeof(div));

}
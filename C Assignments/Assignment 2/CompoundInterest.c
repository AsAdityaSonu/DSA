#include<stdio.h>
#include<math.h>
int main(){

    printf("Enter the amount for which you wants to calculate comppund interest... Rs.");
    float p;
    scanf("%f",&p);

    printf("Enter the rate at which interest is to be calculated:");
    float r;
    scanf("%f",&r);

    printf("Enter the time for which Interest is to be calculated:");
    float t;
    scanf("%f",&t);

    //calculation part
    float ci;
    ci = p*(pow((1+r/100),t));

    printf("The Compound Interst for given amount of money is Rs.%f",ci);

    return 0;
}
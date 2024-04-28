#include<stdio.h>
int main(){
    printf("Enter the basic salary of the person...   \n");
    // Type declaration
    int basic;
    float da,dt;
    //data entry
    scanf("%d",&basic);
    //calculation part
    da = 0.1*basic;
    dt = 0.12*basic;

    float final;

    final = basic+da+dt;

    //output
    printf("The Gross salary of the person is: Rs. %f\n", final);
    return 0;

}
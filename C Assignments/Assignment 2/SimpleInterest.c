#include<stdio.h>
int main(){
    printf("Enter the amount of money borrowed or given... Rs.");
    float p;
    scanf("%f",&p);

    printf("Enter the rate at which interest is taken... ");
    float r;
    scanf("%f",&r);

    printf("Enter the time period (in Years) for which interst is taken or borrowed... ");
    float t;
    scanf("%f",&t);

    //calculation part
    float final;
    final=(p*t*r)/100;

    float amount = final+p;

    printf("---------------------------------------------------------------------\n");

    printf("The final amount after adding interest Rs.%f",final);
    printf(" at interest rate of %f",r);
    printf(" percent is Rs.%f\n",amount);

    printf("---------------------------------------------------------------------");
    return 0;
}
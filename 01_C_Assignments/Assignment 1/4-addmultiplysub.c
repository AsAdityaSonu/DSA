#include <stdio.h>
int main(){
    int first,second,add, subtract,multiply;
    printf("Enter any two integers: \n");
    
    //data entry
    scanf("%d%d",&first,&second);
    
    //calculation part
    add = first + second;
    subtract = first - second;
    multiply = first * second;

    printf("Sum = %d\n", add);
    printf("Subtract = %d\n", subtract);
    printf("Multiply = %d\n", multiply);
    printf("-------------------------------------------------");

}
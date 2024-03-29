#include<stdio.h>
int main(){
    int x, n,num1;
    printf("Enter the value of x:");
    scanf("%d",&x);
    printf("Enter the value of n:");
    scanf("%d",&n);

    //value of x
    num1 = x;   
    //value of n
    n--;

    while (n!=0)
    {
        /* code */
        x=x*num1;
        n--;
    }
    printf("Result: %d",x);
    return 0;
    
}
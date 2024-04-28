#include<stdio.h>
int main(){
    printf("Enter any five digits number... \n");
    int n, reversed=0,remainder;
    scanf("%d",&n);

    while (n!=0)
    {
        /* code */
        remainder= n%10;
        reversed= reversed*10+remainder;
        n /= 10;
    }

    printf("Reversed number = %d",reversed);
    return 0;

    
}
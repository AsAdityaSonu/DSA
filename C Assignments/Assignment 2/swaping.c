#include<stdio.h>
int main(){
    printf("Enter any two values... \n");
    
    //Declaration of data type
    int c,d;

    //data input
    scanf("%d%d",&c,&d);

    //Operation Part
    c= c+d;
    d= c-d;
    c= c-d;

    //Output Part
    printf("The new value of c is %d\n",c);
    printf("The new value of d is %d\n",d);
    return 0;

    
}
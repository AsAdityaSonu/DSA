#include<stdio.h>
int main(){
    int a ,b,c;
    printf("Enter three values simultaneously:\n");
    scanf("%d%d%d",&a,&b,&c);

    // if (a>b&&a>c)
    // {
    //     /* code */
    //     printf("a is gratest among all");
    // }else if(b>a && b>c){
    //     printf("b is greatest among all");
    // }else{
    //     printf("c is greatest amonga all.");
    // }

    int big;
    big= (a>b && a>c) ? (a):((b>a && b>c)? (b):(c));
    printf("The greatest among all is %d",big);
    return 0; 
}
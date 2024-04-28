#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter any value of a ");
    scanf("%d",&a);

    printf("Enter any value of b ");
    scanf("%d",&b);

    printf("Enter any value of c ");
    scanf("%d",&c);

    float root1,root2;
    float u;

    u = sqrt(pow(b,2)-4*a*c);
    
    root1=(-b+u)/(2*a);

    root2=(-b-u)/(2*a);

    printf("The first root for given value of equation is %f\n",root1);
    printf("The second root for given value of equation is %f\n",root2);

    return 0;


}
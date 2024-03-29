#include<stdio.h>
int main(){
    int a[10],b[10];
    int i,j;
    int pos, num;
    int store;

    //Taking array
    printf("Enter an array:\t");
    for ( i = 0; i <= 4 ; i++)
    {
        /* code */
        scanf("%d",&a[i]);
    }

    printf("Enter any positon in which you wants to insert value:\n");
    scanf("%d",&pos);
    printf("Enter any number you wants to insert:");
    scanf("%d",&num);

    //inserting value
    for ( i = 4; i>=pos; i--)
    {
        /* code */
        a[i+1]=a[i];
    }

    a[pos]=num;
    

    //Print
    for ( j = 0; j < 6; j++)
    {
        /* code */
        printf("%d\t",a[j]);
    }
    return 0;
}

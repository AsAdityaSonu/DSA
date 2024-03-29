#include<stdio.h>
int main(){
    int a[10],b[10];
    int pos,n;
    int i,j;
    printf("Enter the values:");
    //Data Input
    for(i=0;i<5;i++){
        scanf("%d",&a[i]);
    }

    //Information about deleting data
    printf("Enter the number you wants to delete: from array: ");
    scanf("%d",&pos);

    //Checking positon
    for ( i = 0; i < 5; i++)
    {
        /* code */
        if (pos== a[i]){
            n=i;
            break;}
    }
    //Date Transfer

    for ( i = n; i < 4; i++)
    {
        /* code */
        a[n]=a[n+1];
    }
    
    //Printing output
    for(j=0;j<4;j++){
        printf("%d\t",a[j]);
    }

    printf("\n");
}
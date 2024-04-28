#include<stdio.h>
int main(){
    int i,j,num;
    int ar[10],br[10];
    //Number of elements in Matrix
    printf("Enter the number of elements in matrix:");
    scanf("%d",&num);
    //first matirx
    printf("Enter the elements of first matrix:");
    for(i=0;i<num;i++){
        scanf("%d",&ar[i]);
    }
    //second marix
    printf("Enter the elements of first matrix:");
    for ( i = 0; i < num; i++)
    {
        scanf("%d",&br[i]);
    }

    printf("The sum of corresponding elements of both the matrix are:\n ");
    for(j=0;j<num;j++){
    printf("%d \t\n",ar[j]+br[j]);
    }
    
    printf("The average of corresponding elements of both the matrixes are:\n ");
    for(j=0;j<num;j++){
    printf("%d \t",(ar[j]+br[j])/2);
    }
}
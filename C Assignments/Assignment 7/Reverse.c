#include<stdio.h>
int main(){
    int ar1[10], ar2[10];
    int i,j,k;
    printf("Enter any five numbers:");

    for(i=0; i<5; i++){
        scanf("%d",&ar1[i]);
    }

    //Storing value
    for(k=3;k<6;k++){
        ar2[k]=ar1[4-k];
    }


    //Transfer of value
    for(j=0;j<5;j++){
        ar1[j]=ar1[4-j];
        // printf("%d\t\n",ar1[j]);
    }

    //retransfer of remaining values
    for(k=3;k<6;k++){
        ar1[k]=ar2[k];
    }

    for (j=0; j<=4; j++){
        printf("%d\t",ar1[j]);
    }
    return 0;
}
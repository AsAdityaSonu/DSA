#include<stdio.h>
int main(){
    //Data Type Declaration
    int hardness,tensile;
    float carbon;
    //data input
    printf("Enter the hardness of steel in the given sample of steel:");
    scanf("%d",&hardness);
    printf("Enter the content of carbon in steel:");
    scanf("%f",&carbon);
    printf("Enter the tensile strength of the steel:");
    scanf("%d",&tensile);
    //operation part
    if(hardness>50 && carbon < 0.7 && tensile >5600){
        printf("The given sample of steel is Grade 10 steel.");
    }else if (hardness> 50 && carbon < 0.7){
        printf("The given sample of steel is Grade 9 steel.");
    }else if (carbon<0.7 && tensile > 5600 ){
        printf("The given sample of steel is Grade 8 steel.");
    }else if (hardness>50 && tensile >5600){
        printf("The given sample of steel is Grade 7 steel.");
    }else if (hardness>50 || carbon <0.7 || tensile > 5600){
        printf("The given sample of steel is Grade 6 steel.");
    }else {
        printf("The given sample of steel is Grade 5 steel.");
    }
}
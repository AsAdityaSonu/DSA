#include<stdio.h>
#include<math.h>
int main(){
    float x,y,z;
    printf("Enter any angle...\n");
    scanf("%f",&x);
    y = x*3.14/180;
    z = cos(y);
    printf("The cosine value for the given angle is %-10.2fthe",z);

    printf("%f\n",ceil(9.7));
    printf("%f\n",floor(7.8));
    return 0;
}
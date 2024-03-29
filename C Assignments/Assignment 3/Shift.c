#include<stdio.h>
int main(){
    unsigned char a =64,b=82;
    printf("a<<1 = %d\n", a>>3);
    
    // The result is 00010010 
    printf("b<<1 = %d\n", b<<1);
    return 0;

}
#include<stdio.h>
int main(){
    //data type declaration
	int n1=0,n2=1,next_num,times,i;
	
	//scannig value
    printf("Enter the number of timmes you wnats to run the loop: ");
    scanf("%d",&times);
    
	//print
    printf("%d\t%d\t",n1,n2);
    
	//loop
    for ( i = 1; i < times; i++)
    {
        /* code */
        printf("%d\t",next_num);
        n1=n2;
        n2=next_num;
        next_num= n1+n2;
    }
    
    
}

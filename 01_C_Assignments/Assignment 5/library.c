#include<stdio.h>
int main(){
    int num;
    printf("Enter the no. of days the you are late to return the book: ");
    scanf("%d",&num);

    //operation part
    if (num<=5)
    {
        /* code */
        printf("You have to pay Rs 0.5 (50 paisa) as fine.");
    }else if (num >=6 && num<=10){
        printf("You have to pay Rs 1 as fine.");
    }else if (num > 10 && num <= 30){
        printf("You have to pay Rs 5 as fine.");
    }else if (num >30){
        printf("your membership has been cancelled.");
    }
    return 0;
}
 #include<stdio.h>
int main(){
    char num;
    printf("Enter any character you wants to check: ");
    scanf("%c",&num);

    if (num>='a'&& num<='z')
    {
        printf("The given charcter is a small letter.");
    }else if(num>='A'&& num<='Z'){
        printf("The given charcter is a capital letter.");
    }else if(num>='0' && num <='9'){
        printf("The given charcter is a number.");
    }else {
        printf("The given charcter is a special character.");
    }
    
}
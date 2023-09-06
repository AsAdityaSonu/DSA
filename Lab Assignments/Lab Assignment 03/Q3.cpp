// Check if an expr has Balanced parentheses
#include<iostream>
 using namespace std;
  #define MAX  100

struct Stack{
    int arr[MAX];
    int top;
    Stack(){
        top=-1;
    }
};
int len(string x){
    int i=0;
    while (x[i] != '\0'){
        i++;
    }
    return i;
}

bool isEmpty(Stack &Stk){
    if(Stk.top == -1){
        return true;
    }
    return false;
}
void push( Stack& Stk,int val){
    Stk.top += 1;
    Stk.arr[Stk.top] = val;
}
char peek(Stack &Stk){
    return Stk.arr[Stk.top];
}

char pop(Stack &Stk){
    char x = Stk.arr[Stk.top];
    Stk.top -= 1;
    return x;
}

bool check(string str){
    Stack Stk;
    for (int i=0;i<len(str);i++){
        if (str[i] == '{' || str[i] == '[' || str[i] == '('){
                push(Stk,str[i]);
        }
        else{
            if ((peek(Stk)=='(' && str[i] == ')') || (peek(Stk)=='[' && str[i] == ']') || (peek(Stk)=='{' && str[i] == '}')){
                pop(Stk);
            }
        }
    }
    if (isEmpty(Stk)){
        return true;
    }
    return false;
}
int main()
{
    string str  = "[{()}]";
    cout<<check(str);
    return 0;
}
#include<iostream>
using namespace std;

void c(char &a){
    char lower;
    lower= (int)a-32;
    cout<<lower<<endl;
}

int main(){
    char a;
    cout<<"Enter a character you wants to convert: ";
    cin >> a;

    c(a);
}
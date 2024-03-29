#include<iostream>
using namespace std;

class fun{
    public:
    int rem(int &x){
        x=x*x;
        return x;
    }
};

int main(){
    int n=90;
    fun f1;
    cout<<n<<endl; //Function hasn't been called yet
    cout<<f1.rem(n)<<endl;
    cout<<n<<endl;
}
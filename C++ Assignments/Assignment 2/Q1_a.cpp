#include<iostream>
using namespace std;
class fun{
    int i;
    public:
    int value(int num){
        i=num*3;
        return i;
    }

};

int main(){
    int x=9;
    fun f1;
    cout<<f1.value(x)<<endl;
    cout<<x<<endl;
}
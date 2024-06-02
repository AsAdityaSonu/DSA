#include<iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int temp=0;
            while(num!=0){
                temp+=num%10;
                num/=10;
            }
            num=temp;
            cout<<num;
        }
        return num;
    }
};

int main()
{
    
    return 0;
}
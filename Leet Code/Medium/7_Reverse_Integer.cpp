#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long p=x;
        if(p<0){
            p=p*-1;
        }

        long ans=0;
        while (p){
            ans =ans*10 + p%10;
            p=p/10;
        }

        if(ans>INT_MAX || ans<INT_MIN) return 0;

        if(x<0)
            return -ans;
        else
            return ans;
    }
};

int main()
{
    
    return 0;
}
#include<iostream>
using namespace std;

// Approach 1: Two Pointer
class Solution {
public:
    bool judgeSquareSum(int c) {
        int k = sqrt(c);
        long a=0, b=k;

        while(a<=b){
            if(a*a+b*b<c){
                a++;
            }else if(a*a+b*b>c){
                b--;
            }else{
                return true;
            }
        }

        return false;
    }
};


int main()
{
    
    return 0;
}
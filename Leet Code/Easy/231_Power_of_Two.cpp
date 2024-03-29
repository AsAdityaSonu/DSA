#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==0 || n<0) return 0;
        if(n & (n-1)) return false;
        return 1;
    }
};

int main()
{
    
    return 0;
}
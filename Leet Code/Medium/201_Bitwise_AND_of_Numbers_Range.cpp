#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            ans++;
        }
        return left << ans;
    }
};

int main()
{
    
    return 0;
}
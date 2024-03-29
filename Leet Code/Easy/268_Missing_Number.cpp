#include<iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        vector<int> v(n+1, -1);

        for(int i=0;i<n;i++){
            v[nums[i]]=nums[i];
        }

        for(int i=0;i<n;i++){
            if(v[i]==-1) return i;
        }
        return n;
    }
};

int main()
{
    
    return 0;
}
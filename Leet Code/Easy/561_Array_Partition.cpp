#include<iostream>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans=0;
        for(int i=0;i<nums.size();i=i+2){
            ans += nums[i];
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}
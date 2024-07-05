#include<iostream>
#include<vector>
using namespace std;

// Approach 1
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n= nums.size();
        if(n<=3) return 0;

        sort(nums.begin(), nums.end());

        int ans=INT_MAX;

        for(int i=0;i<=3;i++){
            ans = min(ans, nums[n-1-(3-i)]-nums[i]);
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}
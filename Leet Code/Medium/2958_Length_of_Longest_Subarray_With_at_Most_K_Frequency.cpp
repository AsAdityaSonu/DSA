#include<iostream>
using namespace std;

class Solution {
public:
    // Sliding window
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> v;
        int n=nums.size(), ans=0;

        for(int left =0, right =0; right<n; right++){
            v[nums[right]]++;

            if(v[nums[right]]>k){
                while(nums[left]!=nums[right]){
                    v[nums[left]]--;
                    left++;
                }
                v[nums[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}
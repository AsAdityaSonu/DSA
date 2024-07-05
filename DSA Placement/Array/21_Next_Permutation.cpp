#include<iostream>
#include<vector>
using namespace std;

// Approach: Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        int idx1=-1, idx2=-1;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx1=i;
                break;
            }
        }

        // no break point
        if(idx1==-1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idx1]){
                idx2=i;
                break;
            }
        }

        swap(nums[idx1],nums[idx2]);
        reverse(nums.begin()+idx1+1, nums.end());
    }
};

// Approach: Single Pass Approach
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

int main()
{
    
    return 0;
}
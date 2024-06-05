#include<iostream>
#include<vector>
using namespace std;

// Approach 1: Two Pointer Approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return;

        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[k]=nums[i];
                k++;
            }
        }

        for(int i=k;i<n;i++){
            nums[i]=0;
        }
    }
};

int main()
{
    
    return 0;
}
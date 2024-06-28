#include<iostream>
#include<vector>
using namespace std;

// Brute Force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos, neg;

        for(auto x:nums){
            if(x >= 0){
                pos.push_back(x);
            }
            else{
                neg.push_back(x);
            }
        }

        vector<int> ans;

        for(int i=0;i<pos.size();i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};

// Single Array two pointer
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos=0;
        int neg=1;
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[pos]=nums[i];
                pos+=2;
            }else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// Approach 1: Better Approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int ans=1;
        int temp=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    temp++;
                }else{
                    ans= max(temp, ans);
                    temp=1;
                }
            }
        }

        return max(temp, ans);
    }
};

// Approach 2
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=0) return 0;

        map<int, int> mp;
        for(auto a:nums){
            mp[a]++;
        }

        int ans=0;
        int count=0;
        int temp=INT_MIN;
        for(auto a: mp){
            cout<<a.first<<" ";
            if(temp==a.first-1){
                count++;
                ans=max(ans, count);
                temp=a.first;
            }else{
                temp=a.first;
                count=0;
            }
        }

        return ans+1;
    }
};

int main()
{
    
    return 0;
}
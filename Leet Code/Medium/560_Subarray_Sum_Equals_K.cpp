#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Approach 1: Brute Force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            int sum=nums[i];
            if(sum == k) ans++;     // element itself equal to k

            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                if(sum == k) ans++;     // any point equal to k
            }
        }

        return ans;
    }
};

// Approach 2: Using Hash Map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-k) != mp.end()) ans+=mp[sum-k];
            mp[sum]++;
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}
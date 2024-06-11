#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Approach 1: using map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        
        for(auto a: nums){
            mp[a]++;
        }

        for(auto a: mp){
            if(a.second>n/2){
                return a.first;
            }
        }
        return -1;
    }
};

// Approach 2: Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        int ele;

        for(int i=0;i<n;i++){
            if(count ==0){
                count=1;
                ele=nums[i];
            }
            else if(ele ==nums[i]) count++;
            else count--;
        }

        int count1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele) count1++;
        }

        if(count1>(n/2)) return ele;
        return -1;
    }
};

int main()
{
    
    return 0;
}
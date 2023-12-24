#include<iostream>
using namespace std;

// Solution 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    if(i!=j){
                        v.push_back(i);
                    }
                }
            }
        }
        return v;
    }
};

// Solution 2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> newMap;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int comp = target -nums[i];
            if(newMap.count(comp)){
                return {newMap[comp], i};
            }
            newMap[nums[i]]=i;
        }
        return {};
    }
};

int main()
{
    
    return 0;
}
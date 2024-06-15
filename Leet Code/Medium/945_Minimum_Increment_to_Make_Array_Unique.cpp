#include<iostream>
#include<vector>
using namespace std;

// Approach 01 : Time exceed
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int cost=0;
        int n= nums.size();

        if(n<=1) return 0;

        sort(nums.begin(),nums.end());
        vector<int> v;

        for(int i=n-1;i>=0;i--){
            if(find(v.begin(),v.end(),nums[i])!=v.end()){
                while(find(v.begin(),v.end(),nums[i])!=v.end()){
                    nums[i]++;
                    cost++;
                }
            }
            v.push_back(nums[i]);
        }

        return cost;
    }
};

// Approach 02 
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int cost=0;
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                int extra = nums[i-1]-nums[i]+1;
                nums[i]+=extra;
                cost+=extra;
            }
        }

        return cost;
    }
};

int main()
{
    
    return 0;
}
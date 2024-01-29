#include<iostream>
using namespace std;

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

int main()
{
    
    return 0;
}
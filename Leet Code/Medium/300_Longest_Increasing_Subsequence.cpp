#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        int n=nums.size();
        vector<int> s(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    s[i] = max(s[i], s[j]+1);
                }
            }
        }

        return *max_element(s.begin(), s.end());
    }
};

int main()
{
    
    return 0;
}
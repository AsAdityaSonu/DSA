#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Approach 
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>> p(n);

        for(int i=0;i<n;i++){
            int org = nums[i];
            int mappedNum = org==0 ? mapping[0]:0;
            int index=1;

            while(org>0){
                int rem=org%10;
                mappedNum += index * mapping[rem];
                org/=10;
                index*=10;
            }

            p[i]={mappedNum, i};
        }

        sort(p.begin(), p.end());

        vector<int> ans;
        for(auto pair: p){
            ans.push_back(nums[pair.second]);
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}
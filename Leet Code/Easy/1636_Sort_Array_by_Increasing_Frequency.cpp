#include<iostream>
using namespace std;

// Approach 1
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto n:nums){
            mp[n]++;
        }

        sort(nums.begin(), nums.end(), [&mp](int a, int b) { 
            if (mp[a] != mp[b]) {
                return mp[a] < mp[b];
            }
            return a > b;
        });

        for(auto m:mp){
            cout<<m.first<<" "<<m.second<<endl;
        }

        return nums;
    }
};

int main()
{
    
    return 0;
}
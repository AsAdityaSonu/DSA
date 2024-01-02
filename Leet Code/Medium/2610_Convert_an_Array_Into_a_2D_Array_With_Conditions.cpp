#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        
        for (auto &i : nums){
            mp[i]++;
        }

        while(!mp.empty()){
            vector<int> temp, toErase;
            for(auto &[f,s] : mp){
                temp.emplace_back(f);
                s--;
                if(s==0) toErase.emplace_back(f);
            }
            ans.emplace_back(temp);

            for(auto &i: toErase){
                mp.erase(i);
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}
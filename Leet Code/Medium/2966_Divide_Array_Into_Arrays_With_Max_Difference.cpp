#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v;

        map<int,int> om;

        for(int i=0;i<n;i++){
            om[nums[i]]++;
        }

        vector<int> temp;
        int prev=(om.begin())->first;
        // cout<<prev;
        for (const auto& pair : om) {
            int val = pair.first;
            int key = pair.second;

            while (key > 0) {
                temp.push_back(val);
                key--;
                if (temp.size() == 3) {
                    if(temp[2]-temp[1]>k ||  temp[1]-temp[0]>k || temp[2]-temp[0]>k){
                        return{};
                    }else{
                        v.push_back(temp);
                        temp.clear();
                    }
                }
            }
            prev=val;
        }

        return v;
    }
};

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans(n/3, vector<int>(3));


        int groupIndex = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i+=3){
            if(i+1<n && nums[i + 2] - nums[i] <= k){
                ans[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
                groupIndex++;
            }else{
                return {};
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}
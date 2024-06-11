#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

// Approach 1: SORTING
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// Approach 2: counting red white and blue
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;

        for(auto c: nums){
            mp[c]++;
        }

        int i=0;
        for(auto c : mp){
            int count = c.second;
            while(count>0){
                nums[i]=c.first;
                count--;
                i++;
            }
        }
    }
};

// Approach 3: Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();

        int low=0, mid=0, high =n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    
    return 0;
}
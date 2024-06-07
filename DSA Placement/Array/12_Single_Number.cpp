#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Approach 1: Using Hash Map
int getSingleElement(vector<int> &arr) {
    int n = arr.size();

    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

    return -1;
}

// Approach 2: Using XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        int x=0;

        for(int i=0;i<n;i++){
            x^=nums[i];
        }

        return x;
    }
};

int main()
{
    
    return 0;
}
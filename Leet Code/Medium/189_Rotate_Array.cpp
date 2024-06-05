#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Approach 1: Using Algorithm
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k%n);

        reverse(nums.begin() + k%n, nums.end());
    }
};

// Approach 2: Using Extra Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0)
            return;

        k = k % n;
        if (k == 0)
            return;

        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};

int main()
{
    
    return 0;
}
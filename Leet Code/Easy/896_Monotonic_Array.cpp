#include<iostream>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool ans = 1;

        // Increasing
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                ans = 0;
                break;
            }
        }

        if (ans == 1)
            return 1;

        // Decreasing
        ans=1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                ans = 0;
                break;
            }
        }

        if (ans == 1) {
            return 1;
        } else {
            return 0;
        }
    }
};

int main()
{
    
    return 0;
}
#include<iostream>
using namespace std;

class Solution {
public:
    long long maxCrossingSum(vector<int>& nums, int l, int m, int h) {
        long long sum = 0;
        long long left_part_sum = LLONG_MIN;
        for (int i = m; i >= l; i--) {
            sum += nums[i];
            left_part_sum = max(left_part_sum, sum);
        }

        sum = 0;
        long long right_part_sum = LLONG_MIN;
        for (int i = m + 1; i <= h; i++) {
            sum += nums[i];
            right_part_sum = max(right_part_sum, sum);
        }

        return left_part_sum + right_part_sum;
    }

    long long maxSubArraySum(vector<int>& nums, int l, int h) {
        if (l == h)
            return nums[l];

        int m = (l + h) / 2;

        long long maxLeft = maxSubArraySum(nums, l, m);
        long long maxRight = maxSubArraySum(nums, m + 1, h);
        long long maxCrossing = maxCrossingSum(nums, l, m, h);

        return max(maxLeft, max(maxRight, maxCrossing));
    }

    long long maxSubArray(vector<int>& nums) {
        return maxSubArraySum(nums, 0, nums.size() - 1);
    }
};


int main()
{
    
    return 0;
}
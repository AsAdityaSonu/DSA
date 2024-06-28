#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int i = 0;
        int cost = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                cost++;
            }
        }

        return cost;
    }
};


int main()
{
    
    return 0;
}
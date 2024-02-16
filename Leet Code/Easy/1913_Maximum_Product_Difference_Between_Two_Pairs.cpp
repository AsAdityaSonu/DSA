#include<iostream>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max0=1, max1=1, min1=INT_MAX, min0=INT_MAX;
        for(int x: nums){
            if (x>max0){
                max1=max0;
                max0=x; 
            }
            else max1=max(max1, x);
            if (x<min0) {
                min1=min0;
                min0=x;
            }
            else min1=min(min1, x);
        }
        return max0*max1-min0*min1;
    }
};

int main()
{
    
    return 0;
}
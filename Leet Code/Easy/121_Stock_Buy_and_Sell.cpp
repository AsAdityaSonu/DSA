#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int i=0,j=n-1;
        int mini=INT_MAX, maxi=INT_MIN;

        for (int i = 0; i < prices.size(); i++) {
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i] - mini);
        }

        return (maxi);
    }
};

int main()
{
    
    return 0;
}
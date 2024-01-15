#include<iostream>
using namespace std;

// to keep track of the smallest and second smallest elements encountered so far.
// to check if there is a triplet in array not all needs to be triplet
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for(auto num : nums){
            if(num<=first){
                first=num;
            }else if(num<=second){
                second=num;
            }else{
                return true;
            }
        }

        return false;
    }
};

int main()
{
    
    return 0;
}
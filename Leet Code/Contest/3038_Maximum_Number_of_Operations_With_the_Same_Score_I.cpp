#include<iostream>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sum = nums[0]+nums[1];
        int count=1;
        
        for(int i=2;i<nums.size()-1;i+=2){
            int temp= nums[i]+nums[i+1];
            if(temp != sum){
                break;
            }
            count++;
        }
        
        return count;
    }
};

int main()
{
    
    return 0;
}
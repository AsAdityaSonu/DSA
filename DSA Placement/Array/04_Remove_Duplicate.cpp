#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n=nums.size();

        for(int j=0;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }      

        return i+1;
    }
};

int main()
{
    
    return 0;
}
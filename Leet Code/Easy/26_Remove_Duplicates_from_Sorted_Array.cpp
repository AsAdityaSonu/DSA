#include<iostream>
using namespace std;

// Approach 1: Better than 100% solutions
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

// Approach 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }

        int m=0;
        for(auto i:s){
            nums[m]=i;
            m++;
        }

        return m;

    }
};

int main()
{
    
    return 0;
}
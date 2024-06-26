#include<iostream>
#include<vector>
using namespace std;

// Approach 1: Using Vector
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        vector<int> v(n+1, -1);

        for(int i=0;i<n;i++){
            v[nums[i]]=nums[i];
        }

        for(int i=0;i<n;i++){
            if(v[i]==-1) return i;
        }
        return n;
    }
};

// Approach 2: Using XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int x1=0;
        int x2=0;

        for(int i=0;i<n;i++){
            x1^=nums[i];
            x2^=(i+1);
        }

        return x1^x2;
    }
};

int main()
{
    
    return 0;
}
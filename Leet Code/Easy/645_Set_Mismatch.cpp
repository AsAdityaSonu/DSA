#include<iostream>
using namespace std;

// first
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int d =-1, m=-1;

        for(int i=1;i<=nums.size();i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==i){
                    count++;
                }
            }
            if(count==2){
                d = i;
            }else if(count == 0){
                m=i;
            }
        }

        return {d,m};
    }
};

// second
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1,0);
        int m=0,d=0;

        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }

        for(int i=1;i<v.size();i++){
            if(v[i]==2)d=i;
            if(v[i]==0)m=i;
        }

        return {d,m};
    }
};

int main()
{
    
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int minIndex = -1;
        int n=nums.size();
        //only one element
        if(n==1) return true;

        //no rotation case
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                break;
            } 
            if(i==n-1){
                return true;
            }
            cout<<i<<endl;
        }


        for(int i=0;i<n;i++){
            if(nums[i]>nums[i+1]){
                minIndex=i+1;
                break;
            } 
        }

        int j=minIndex;
        int k=(minIndex+1)%n;
        while(k!=minIndex){
            cout<<j<<" "<<k<<endl;
            if(nums[j]>nums[k]){
                return false;
            }
            j=(j+1)%n;
            k=(k+1)%n;
        }

        return true;
    }
};

int main()
{
    
    return 0;
}
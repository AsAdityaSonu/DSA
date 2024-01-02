#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n,1);
        vector<int> left(n,1);
        vector<int> right(n,1);

        int leftM=1;
        for(int i=0;i<n;i++){
            left[i] = leftM;
            leftM *= nums[i];
        }

        int rightM=1;
        for(int i=n-1;i>=0;i--){
            right[i] = rightM;
            rightM *= nums[i];
        }

        for(int i=0;i<n;i++){
            answer[i]=left[i]*right[i];
        }

        return answer;
    }
};

int main()
{
    
    return 0;
}
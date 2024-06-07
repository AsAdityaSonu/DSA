#include<iostream>
using namespace std;

// Approach: Brute Force
class Solution{
    public:
    int lenOfLongSubarr(int Arr[],  int n, int k) 
    { 
        int count=0;
        // Complete the function
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=Arr[j];
                
                if(sum==k){
                    if(abs(j-i+1)>count) count=abs(j-i+1);
                }
            }
        }
        
        return count;
    } 
};

// Approach: Hash

int main()
{
    
    return 0;
}
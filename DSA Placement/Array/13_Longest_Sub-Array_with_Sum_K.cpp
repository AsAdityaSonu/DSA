// GFG Longest Sub-Array with Sum K Problem (https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1#)    

#include<iostream>
#include<algorithm>
#include<map>
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
class Solution{
    public:
    int lenOfLongSubarr(int Arr[],  int n, int k) 
    { 
        // Complete the function
        map<long long, int> mp;
        long long sum=0;
        int maxLen =0;
        
        for(int i=0;i<n;i++){
            sum+=Arr[i];
            
            if(sum==k) maxLen = max(maxLen, i+1);
            
            long long rem = sum-k;
            
            if(mp.find(rem)!=mp.end()){
                int len = i-mp[rem];
                maxLen = max(maxLen, len);
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxLen;
    } 

};

// Approach: Two Pointer (only for positive numbers)
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        int sum=0;
        int left=0, right =0;
        int maxLen=0;
        
        while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n) sum += a[right];
    }
        
        return maxLen;
    } 

};


int main()
{
    
    return 0;
}
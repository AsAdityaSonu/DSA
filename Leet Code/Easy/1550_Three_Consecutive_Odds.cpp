#include<iostream>
#include<vector>
using namespace std;

// Approach: 100% faster
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        for (int i=0;i<n-2;i++){
            if(arr[i]%2!=0 && arr[i+1]%2!=0 && arr[i+2]%2!=0){
                return 1;
            }
        }

        return 0;
    }
};

// Approach 2: 25% faster
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for (int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                count=0;
            }else{
                count++;
                if(count>=3) return 1;
            }
            cout<<arr[i]<<" "<<count<<endl;
        }

        return 0;
    }
};

int main()
{
    
    return 0;
}
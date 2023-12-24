#include<iostream>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(i%2==0 && s[i]=='1') count++;
            if(i%2!=0 && s[i]=='0') count++;
        }

        return min(count, n-count);
    }
};

int main()
{
    
    return 0;
}